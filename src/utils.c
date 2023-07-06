#include <estia-image.h>

#include "utils.h"

/*
 * Issue : #21 Access a pixel of an image with its coordinates
    pixel* getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y );

 * - void setPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel);

 *

*/

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ) {
    pixelRGB coord;
    coord.R = data[ (y * width + x) * n + 0 ];
    coord.G = data[ (y * width + x) * n + 1 ];
    coord.B = data[ (y * width + x) * n + 2 ];
    return &coord;
}