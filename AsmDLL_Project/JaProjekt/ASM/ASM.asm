.data
byte_array_3 db 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0
shuffle_mask_2 db 4,5,6,7,8,9,10,11,0,1,2,3,12,13,14,15

.code
Procedura proc
mov r10, [rsp + 40] ;Width
push rbx
push rbp
push rdi
push rsi
push r12
push r13
push r14
push r15
mov rsi, rcx 
mov rdi, rdx
inc r8
dec r9

mov rax, r10 ;calculating stride
shl rax, 2
mov r14, rax

mov r15, r10 ; r15 przechowuje szerokoœæ pomniejszon¹ o 1 (bez ramek)
sub r15, 1
movdqu xmm6, xmmword ptr [byte_array_3]
movdqu xmm4, xmmword ptr [shuffle_mask_2]

outer_loop:
	cmp r8, r9
	jge end_here
	mov r13, 1 ;r13 przechowuje aktualny x, tutaj go inicjalizujemy dla wewnêtrznej pêtli

inner_loop:
	cmp r13, r15
	jge outer_inc
	
	mov r11, r13 ;r11 i 'offset' przechowuje offset do aktualnie zmienianego piksela
	shl r11, 2
	mov rax, r8
	mov rbx, r14
	mul rbx
	add r11, rax
	mov r12, r11
	movdqu xmm0, [rsi + r11 - 4] ;wczytywanie pikseli do xmmow
	pmovzxbw xmm0,xmm0
	add r11, r14
	movdqu xmm1, [rsi + r11 - 8]
	pshufb xmm1, xmm4
	pmovzxbw xmm1,xmm1
	paddw xmm0, xmm1
	movhlps xmm1, xmm0
	paddw xmm0, xmm1
	mov r11, r12
	movdqu xmm2, [rsi + r11 + 4]
	sub r11, r14
	movdqu xmm1, [rsi + r11]
	pmovzxbw xmm1,xmm1	
	pmovzxbw xmm2,xmm2
	pand xmm2, xmm6
	paddw xmm1, xmm2
	movhlps xmm2, xmm1
	paddw xmm1, xmm2
	psubusw xmm0,xmm1	;odejmowanie
	packuswb xmm0,xmm0
	mov r11, r12 ;zapis
	xor rax, rax
	movd eax, xmm0
	mov dword ptr [rdi + r11], eax

inner_inc:
	inc r13
	jmp inner_loop

outer_inc:
	inc r8
	jmp outer_loop

end_here:
	xor rax, rax
	pop r15
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