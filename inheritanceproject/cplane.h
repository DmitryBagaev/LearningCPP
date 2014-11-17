#ifndef CPLANE_H_INCLUDED
#define CPLANE_H_INCLUDED
#include <iostream>
#include <cvehicle.h>

using namespace std;

class CPlane : public CVehicle{
public:
    int height;
    int passangers;
    CPlane():CVehicle(), height(2000), passangers(70){}

    void setHeight(int extHeight);
    int getHeight();
    void setPassangers(int pass);
    int getPassangers();
};

#endif
