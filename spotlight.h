
#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H
#include <string>
#include "image.h"
using namespace std;
class Spotlight:public Image
{
public:
    Spotlight(string filename,int x,int y);
    void changeSpotPoint(int x, int y);
    int x;
    int y;
    string filename;

};

#endif // SPOTLIGHT_H

