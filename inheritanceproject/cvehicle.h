#ifndef CVEHICLE_H_INCLUDED
#define CVEHICLE_H_INCLUDED

#include <iostream>

using namespace std;

class CVehicle{
public:
    int positionX;
    int positionY;
    int price;
    int creationTime;
    int speed;

    CVehicle(): positionX(0), positionY(0), price(0), creationTime (0), speed(0){}
    virtual void setX(int posX);
    virtual int getX();
    virtual void setY(int posY);
    virtual int getY();
    virtual void setPrice(int extPrice);
    virtual int getPrice();
    virtual void setCreationTime(int time);
    virtual int getCreationTime();
    virtual void setSpeed(int extSpeed);
    virtual int getSpeed();
};
#endif
