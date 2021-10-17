

#ifndef IMAGE_H
#define IMAGE_H
#include "PNG.h"
#include "HSLAPixel.h"
class Image : public PNG
{
public:
    Image(string filename);
    Image();
    Image lighten(double amount);
    Image rotateColor(double angle);
    Image saturate(double amount);

};

#endif // IMAGE_H
