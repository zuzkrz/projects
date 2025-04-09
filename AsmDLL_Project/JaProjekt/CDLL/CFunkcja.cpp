#include "pch.h"
#include "CFunkcja.h"

void Cfunckja(uint8_t* original, uint8_t* result, int start, int end, int width, int height) {
    int mask[3][3] = {
        {0, -1, -1},
        {1, 1, -1},
        {1, 1, 0}
    };

    int BytePerPxl = 4;
    int Stride = width * BytePerPxl;

    for (int y = start + 1; y < end - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int red = 0, green = 0, blue = 0;

            // Apply the mask
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int index = (y + i) * Stride + (x + j) * BytePerPxl;
                    blue += original[index] * mask[i + 1][j + 1];
                    green += original[index + 1] * mask[i + 1][j + 1];
                    red += original[index + 2] * mask[i + 1][j + 1];
                }
            }

            // Assign computed values to result
            int resultIndex = y * Stride + x * BytePerPxl;
            result[resultIndex] = fmin(fmax(blue, 0), 255);
            result[resultIndex + 1] = fmin(fmax(green, 0), 255);
            result[resultIndex + 2] = fmin(fmax(red, 0), 255);
            result[resultIndex + 3] = original[resultIndex + 3];
        }
    }
    /*
    //Copying first and last row of pixels from original to result
    for (int x = 0; x < width; x++) {
        int index = x * BytePerPxl;
        result[index] = original[index];
        result[index + 1] = original[index + 1];
        result[index + 2] = original[index + 2];
        index = Stride * (height-1) + x*BytePerPxl;
        result[index] = original[index];
        result[index + 1] = original[index + 1];
        result[index + 2] = original[index + 2];
    }
    //Copying first and last column of pixels from original to result
    for (int y = 1; y < height; y++) {
        int index = y * Stride;
        result[index] = original[index];
        result[index + 1] = original[index + 1];
        result[index + 2] = original[index + 2];
        index = (y+1) * Stride - BytePerPxl;
        result[index] = original[index];
        result[index + 1] = original[index + 1];
        result[index + 2] = original[index + 2];
    }
    */
}