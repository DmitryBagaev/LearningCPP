#include <cvehicle.h>


void CVehicle::setX(int posX)
{
    positionX = posX;
}

int CVehicle::getX()
{
    return positionX;
}

void CVehicle::setY(int posY)
{
    positionY = posY;
}

int CVehicle::getY()
{
    return positionY;
}

void CVehicle::setPrice(int extPrice)
{
    price = extPrice;
}

int CVehicle::getPrice()
{
    return price;
}

void CVehicle::setCreationTime(int time)
{
    creationTime = time;
}

int CVehicle::getCreationTime()
{
    return creationTime;
}

void CVehicle::setSpeed(int extSpeed)
{
    speed = extSpeed;
}

int CVehicle::getSpeed()
{
    return speed;
}
