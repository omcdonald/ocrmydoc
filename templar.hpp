/*
 * Header for library file for OCR module.
 *
 * Author: Milosz Kosmider
 */

namespace Templar
{
    /*
     * The method that actually processes the region.
     */
    char* Process(const char* language, const unsigned char* imagedata, int bytes_per_pixel, int bytes_per_line, int width, int height);
    int Debug();
}
