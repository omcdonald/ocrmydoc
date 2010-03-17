  /*
 * Library file for OCR module.
 *
 * Author: Milosz Kosmider
 */

#include "tesseract/baseapi.h"
#include "templar.hpp"
#include "sax.hpp"

#ifndef NULL
#define NULL 0L
#define _CUSTOM_NULL
#endif

char* Templar::Process(const char* language, const unsigned char* imagedata, int bytes_per_pixel, int bytes_per_line, int width, int height)
{
    TessBaseAPI::InitWithLanguage(NULL, NULL, language, NULL, false, 0, NULL);
    char* text = TessBaseAPI::TesseractRect(imagedata, bytes_per_pixel, bytes_per_line, 0, 0, width, height);
    TessBaseAPI::End();
   
    return text;
}

char* Templar::Debug()
{
    return "Hello";
}

#ifdef _CUSTOM_NULL
#undef NULL
#undef _CUSTOM_NULL
#endif
