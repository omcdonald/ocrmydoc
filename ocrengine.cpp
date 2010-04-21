/* 
 * Templar OCR engine source.
 * 
 * Author: Milosz Kosmider
 */

#include <cstring>

#include "tesseract/baseapi.h"
#include "tesseract/imgs.h"
#include "tiffio.h"
void read_tiff_image(TIFF* tif, IMAGE* image); //bug in tiffio.h?

#include "ocrengine.hpp"

#ifndef NULL
#define NULL 0L
#define NULL_DEFINED
#endif

namespace Templar {
    namespace OCREngine {
        bool initialized = false;
        unsigned char* imagedata;
        int image_width;
        int image_height;
        int bytes_per_line;
        int bytes_per_pixel;

        int Start(const char* image_file)
        {
            int exit_status = 0;
            if (!initialized)
            {
                TIFF* tiff = NULL;
                tiff = TIFFOpen(image_file, "r");

                if (tiff != NULL)
                {
                    IMAGE image;
                    read_tiff_image(tiff, &image);

                    image_width = image.get_xsize();
                    image_height = image.get_ysize();
                    int bpp = image.get_bpp();

                    bytes_per_line = check_legal_image_size(image_width,
                            image_height, bpp);
                    bytes_per_pixel = bpp / 8;

                    unsigned char* buffer = image.get_buffer();
                    int buffer_length = bytes_per_line * image_height;
                    imagedata = new unsigned char[buffer_length];
                    memcpy(imagedata, buffer,
                            buffer_length * sizeof(unsigned char));

                    ::TessBaseAPI::SimpleInit(NULL, "eng", false);

                    initialized = true;
                }
                else
                {
                    exit_status = 1;
                }

                TIFFClose(tiff);
            }
            else
            {
                exit_status = 2;
            }

            return exit_status;
        }

        char* Run(int x, int y, int w, int h)
        {
            if (initialized)
            {
                int x_safe = x < 0 ? 0 : (x > image_width ? image_width : x);
                int y_safe = y < 0 ? 0 : (y > image_height ? image_height : y);
                int w_safe = x < 0 ? x + w :
                        (w > image_width - x_safe ? image_width - x_safe : w);
                int h_safe = y < 0 ? y + h :
                        (h > image_height - y_safe ? image_height - y_safe : h);

                return ::TessBaseAPI::TesseractRect(imagedata, bytes_per_pixel,
                        bytes_per_line, x_safe, y_safe, w_safe, h_safe);
            }
            else
            {
                return NULL;
            }
        }

        void Stop()
        {
            if (initialized)
            {
                delete [] imagedata;
                ::TessBaseAPI::End();
                initialized = false;
            }
        }
    }
}

#ifdef NULL_DEFINED
#undef NULL
#undef NULL_DEFINED
#endif
