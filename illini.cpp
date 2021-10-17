#include "illini.h"

Illini::Illini (string filename,int color1,int color2):Image(filename)
{
    for(unsigned x = 0; x < width() ; x++)
    for(unsigned y = 0; y < height(); y++)
    {
       //reference on the pixel
       HSLAPixel &P = getPixel(x, y);


      if(min(360-abs(P.h-color1),abs(P.h-color1)) > min(360-abs(P.h-color2),abs(P.h-color2))){
          P.h =color2;
      }else{
          P.h =color1;
      }



    }
}
