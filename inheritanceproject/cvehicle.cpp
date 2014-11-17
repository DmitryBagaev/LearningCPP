#include <cvehicle.h>


void CVehicle::setX(int arg)
{
    positionX = arg;
}

int CVehicle::getX()
{
    cout << "Parent getX" << endl;
    return positionX;
}

void CVehicle::setY(int arg)
{
    positionY = arg;
}

int CVehicle::getY()
{
    cout << "Parent getY" << endl;
    return positionY;
}

void CVehicle::setPrice(long arg)
{
    price = arg;
}

long CVehicle::getPrice()
{
    return price;
}

void CVehicle::setCreationTime(int arg)
{
    creationTime = arg;
}

int CVehicle::getCreationTime()
{
    return creationTime;
}

void CVehicle::setSpeed(int arg)
{
    speed = arg;
}

int CVehicle::getSpeed()
{
    return speed;
}
