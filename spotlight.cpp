

#include "spotlight.h"
#include <string>
#include "image.h"
#include <math.h>

Spotlight::Spotlight(string filename,int X,int Y):Image(filename),x(X),y(Y),filename(filename)
{



    for(unsigned x = 0; x < width()  ; x++){
       for(unsigned y = 0; y < height(); y++)
       {
          //reference on the pixel
          HSLAPixel &P = getPixel(x, y);

               double distance=sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
               double decrease = 1-distance*0.5/100 ;
               if (distance>160) {
                   decrease=0.2;
               }

               P.l = decrease*P.l;
             }

}


}
void Spotlight::changeSpotPoint(int centerX, int centerY){
 

    for(unsigned X = 0; X < width()  ; X++){
       for(unsigned Y = 0; Y < height(); Y++)
       {
          //reference on the pixel
          HSLAPixel &P = getPixel(X, Y);

               double distance1=sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
               double distance=sqrt((X-centerX)*(X-centerX)+(Y-centerY)*(Y-centerY));
               double decrease = 1-distance*0.5/100 ;
               double increase = 1-distance1*0.5/100 ;
               if (distance1>160) {
                   increase=0.2;
}


                P.l =P.l/increase;


               if (distance>160) {
                   decrease=0.2;
               }

               P.l = decrease*P.l;

               }


             }

}

