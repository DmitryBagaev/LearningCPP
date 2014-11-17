#ifndef CVEHICLE_H_INCLUDED
#define CVEHICLE_H_INCLUDED

#include <iostream>

using namespace std;

class CVehicle{
public:
    int positionX;
    int positionY;
    long price;
    int creationTime;
    int speed;

    CVehicle(): positionX(0), positionY(0), price(0), creationTime (0), speed(0){}
    void setX(int arg);
    int getX();
    void setY(int arg);
    virtual int getY();
    void setPrice(long arg);
    long getPrice();
    void setCreationTime(int arg);
    int getCreationTime();
    void setSpeed(int arg);
    int getSpeed();
};
#endif
