
#include "image.h"

#include <iostream>
#include <iomanip>
#include <string>
#include "HSLAPixel.h"



Image::Image(string  filename ){
    readFromFile(filename);

}

Image::Image( ){

}
Image Image::lighten(double amount){

    for(unsigned x = 0; x < width() ; x++)
    for(unsigned y = 0; y < height(); y++)
    {
       //reference on the pixel
       HSLAPixel &P = getPixel(x, y);
     if(P.l+amount<=1 && P.l+amount>=0){
       P.l += amount;
   }else if(P.l+amount <0){
         P.l =0;
}
     else if(P.l+amount>1){
         P.l =1;
     }

    }
return *this;
}
Image Image::rotateColor(double angle){

    for(unsigned x = 0; x < width() ; x++){
    for(unsigned y = 0; y < height(); y++){
    {
       //reference on the pixel
       HSLAPixel &P = getPixel(x, y);

       //modifiy the element of P


          P.h += angle;

        if(P.h>=360){

       while(P.h>=360){
           P.h-=360;
       }


       }else if(P.h<0){
          while(P.h<0){
              P.h+=360;
          }

      }
    }

}

}
    return *this;
}
Image Image::saturate(double amount){
    for(unsigned x = 0; x < width() ; x++){
    for(unsigned y = 0; y < height(); y++)
    {
       //reference on the pixel
       HSLAPixel &P = getPixel(x, y);
     if(amount+P.s<=1 && P.s+amount>=0){
       P.s += amount;
   }else if(P.s+amount <0){
         P.s =0;
}
     else if(P.s+amount>1){
         P.s =1;
     }





}
    }
 return *this;
}
