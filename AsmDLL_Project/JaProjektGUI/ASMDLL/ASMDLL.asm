; Temat: Filtr uwypuklaj¹cy
; Data wykonania: 24.01.2025
; Autor: Zuzanna Krzysztofik
;		 Semestr 5, Rok 3

.data
;Tablica potrzebna do zerowania czesci xmm
byte_array_3 db 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0
;Tablica potrzebna do przesuwania pikseli w xmm [1, 2, 3, 4] -> [2, 3, 1, 4]
shuffle_mask_2 db 4,5,6,7,8,9,10,11,0,1,2,3,12,13,14,15

; Parametry: wskaznik na oryginalna bitmape, wskaznik na koncowa bitmape, poczatek podzielonej wysokosci,
;            koniec podzielonej wysokosci, szerokosc bitmapy
.code
Procedura proc
mov r10d, [rsp + 40] ;wyciaganie wysokosci z stosu 

push rbx	;przenoszenie rejestrow na stos
push rbp
push rdi
push rsi
push r12
push r13
push r14
push r15

mov rsi, rcx	; przenoszenie wskaznikow do oryginalnej i koncowej bitmapy do rsi i rdi
mov rdi, rdx

inc r8			; poczatek przerabianej wysokosci + 1 by miec pewnosc, ze algorytm nie wyjdzie poza zakres
dec r9			; koniec przerabianej wysokosci + 1 by miec pewnosc, ze algorytm nie wyjdzie poza zakres

mov rax, r10	;obliczanie stride
shl rax, 2
mov r14, rax

mov r15, r10	;r15 przechowuje szerokoœæ pomniejszon¹ o 1 (bez ramek)
sub r15, 1
movdqu xmm6, xmmword ptr [byte_array_3]		;wczytywanie uzywanych tablic do xmm przed loop
movdqu xmm4, xmmword ptr [shuffle_mask_2]	;wczytywanie uzywanych tablic do xmm przed loop

outer_loop:
	cmp r8, r9		;sprawdzenie warunku pêtli
	jge end_here
	mov r13, 1		;r13 przechowuje aktualny x, tutaj go inicjalizujemy dla wewnêtrznej pêtli

inner_loop:
	cmp r13, r15	;sprawdzenie warunku pêtli
	jge outer_inc
	
	mov r11, r13	;r11 przechowuje wskaznik do aktualnie zmienianego piksela
	shl r11, 2
	mov rax, r8
	mov rbx, r14
	mul rbx
	add r11, rax
	mov r12, r11

	movdqu xmm0, [rsi + r11 - 4]	;wczytywanie pikseli (maska kod 1) do xmmo
	pmovzxbw xmm0,xmm0				;rozszerzenie byte -> word 
	add r11, r14
	movdqu xmm1, [rsi + r11 - 8]	;wczytywanie pikseli (maska kod 1) do xmmo
	pshufb xmm1, xmm4				;zmiana kolejnosci pikseli w xmm
	pmovzxbw xmm1,xmm1				;rozszerzenie byte -> word 
	paddw xmm0, xmm1				;dodwanie kazdego z 4 pikseli do siebie
	movhlps xmm1, xmm0
	paddw xmm0, xmm1
	mov r11, r12
	movdqu xmm2, [rsi + r11 + 4]	;wczytywanie pikseli (maska kod -1) do xmmo
	sub r11, r14
	movdqu xmm1, [rsi + r11]		;wczytywanie pikseli (maska kod -1) do xmmo
	pmovzxbw xmm1,xmm1				;rozszerzenie byte -> word 
	pmovzxbw xmm2,xmm2				;rozszerzenie byte -> word 
	pand xmm2, xmm6					;wyzerowanie czesci xmm (nie potrzebny piksel)
	paddw xmm1, xmm2				;dodwanie kazdego z 3 pikseli do siebie
	movhlps xmm2, xmm1
	paddw xmm1, xmm2
	psubusw xmm0,xmm1				;odejmowanie dodanych pikseli (maska kod 1) 
	packuswb xmm0,xmm0				;powrot byte <- word 

	mov r11, r12					;zapis do koncowej bitmapy
	xor rax, rax
	movd eax, xmm0
	mov dword ptr [rdi + r11], eax

inner_inc:
	inc r13				;inkrementacja o 1
	jmp inner_loop

outer_inc:
	inc r8				;inkrementacja o 1
	jmp outer_loop

end_here:
	xor rax, rax
	pop r15				;przywrocenie wartosci rejestrow ze stosu
	pop r14
	pop r13
	pop r12
	pop rsi
	pop rdi
	pop rbp
	pop rbx
	ret

Procedura endp
end