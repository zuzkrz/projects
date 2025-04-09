#include "pch.h"
#include "CFunkcja.h"

/*
 * Temat: Filtr uwypuklaj�cy
 * Data wykonania: 24.01.2025
 * Autor: Zuzanna Krzysztofik
 *  Semestr 5, Rok 3
 */
// Parametry: wskaznik na oryginalna bitmape, wskaznik na koncowa bitmape, poczatek podzielonej wysokosci,
//            koniec podzielonej wysokosci, szerokosc bitmapy
void Cfunckja(uint8_t* original, uint8_t* result, int start, int end, int width) {
    int mask[3][3] = {
        {0, -1, -1},
        {1, 1, -1},
        {1, 1, 0}
    };

    int BytePerPxl = 4;                 // ilo�� bajt�w na piksel
    int Stride = width * BytePerPxl;    // ilo�� bajt�w w jednym wierszu bitmapy


    // p�tle do przesuwanie si� po ka�dym pikselu bitmapy z pomini�ciem ramki
    for (int y = start + 1; y < end - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int red = 0, green = 0, blue = 0;

            // Nak�adanie maski i kalkulowanie warto�ci dla ka�dej sk�adowej piksela
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int index = (y + i) * Stride + (x + j) * BytePerPxl;
                    blue += original[index] * mask[i + 1][j + 1];
                    green += original[index + 1] * mask[i + 1][j + 1];
                    red += original[index + 2] * mask[i + 1][j + 1];
                }
            }

            // Zapis do ko�cowej bitmapy z wykorzystaniem normalizacji
            int resultIndex = y * Stride + x * BytePerPxl;
            result[resultIndex] = fmin(fmax(blue, 0), 255);
            result[resultIndex + 1] = fmin(fmax(green, 0), 255);
            result[resultIndex + 2] = fmin(fmax(red, 0), 255);
            result[resultIndex + 3] = original[resultIndex + 3];
        }
    }
}