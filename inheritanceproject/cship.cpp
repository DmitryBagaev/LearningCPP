#include <cship.h>

void CShip::setPassangers(int pass)
{
    passangers = pass;
}

int CShip::getPassangers()
{
    return passangers;
}

void CShip::setDirection(string dir)
{
    direction = dir;
}

string CShip::getDirection()
{
    return direction;
}

int CShip::getX()
{
    cout << "Child setX" << endl;
    return positionX;
}

int CShip::getY()
{
    cout << "Child setY" << endl;
    return positionY;
}
