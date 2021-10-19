

#ifndef IMAGE_H
#define IMAGE_H
#include "PNG.h"
#include "HSLAPixel.h"
class Image : public PNG
{
public:
    Image(string filename);
    Image();
    void lighten(double amount);
    void rotateColor(double angle);
    void saturate(double amount);

};

#endif // IMAGE_H
