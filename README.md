# HSLA Images

This project consists of manipulating images by adjusting the HSL color space properties (hue,saturation,luminance).

# Transformations:

## Saturation:

Changing the saturation by a specific amount using the following method:

    void Image::saturate(double amount){
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

## Rotating colors

Increasing the hue of each pixel by an angle using the following method:

    void Image::rotateColor(double angle){

    for(unsigned x = 0; x < width() ; x++){
    for(unsigned y = 0; y < height(); y++){
    {
       HSLAPixel &P = getPixel(x, y);
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
}

## Lighten

Changing the luminance of each pixel by amount using :

    void Image::lighten(double amount){

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

    }

## Grayscale

Eliminating all the colors and representing the image using only a grayscale level using:

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

## Illini

Replacing the hue of each pixel by either the first or the second color that were defined as attributes.The choice is based on the closest color.

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

## Spotlight

A Spotlight image create a spotlight centered at a given point centerX, centerY defined as attributes.

A spotlight adjusts the luminance of a pixel based on the Euclidean distance the pixel is away from the center by decreasing the luminance by 0.5% per 1 pixel, up to 80% derease of luminance at a distance up to 160 pixels away.

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

### Changing the spotlight

Changing the position of the spotlight.
       
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




