#ifndef CSHIP_H_INCLUDED
#define CSHIP_H_INCLUDED
#include <iostream>
#include <cvehicle.h>

using namespace std;
class CShip : public CVehicle{
public:
    int passangers;
    string direction;

    CShip():CVehicle(), passangers(50), direction("Somewhere") {}
    void setPassangers(int pass);
    int getPassangers();
    void setDirection(string dir);
    string getDirection();
};
#endif
