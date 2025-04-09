#pragma once
#ifdef CFunkcja_EXPORTS
#define CFunkcja_API __declspec(dllexport)
#else
#define CFunkcja_API __declspec(dllimport)
#endif
extern "C" CFunkcja_API void Cfunckja(uint8_t* original, uint8_t* result, int start, int end, int width, int height);