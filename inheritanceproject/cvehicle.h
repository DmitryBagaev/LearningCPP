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
    CVehicle(): positionX(0), positionY(0), price(-10), creationTime (-10), speed(0){}
    virtual void setPositionX(int posX);
    virtual int getPositionX();
    virtual void setPositionY(int posY);
    virtual int getPositionY();
    virtual void setPrice(int extPrice);
    virtual int getPrice();
    virtual void setCreationTime(int time);
    virtual int getCreationTime();
    virtual void setSpeed(int extSpeed);
    virtual int getSpeed();
};
#endif
