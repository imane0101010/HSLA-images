#include "grayscale.h"
#include "image.h"
Grayscale::Grayscale(string filename):Image(filename)
{
    for(unsigned x = 0; x < width() ; x++)
    for(unsigned y = 0; y < height(); y++)
    {
       //reference on the pixel
       HSLAPixel &P = getPixel(x, y);
       P.s =0;
       //modifiy the element of P
    }
}



