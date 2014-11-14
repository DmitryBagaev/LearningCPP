#ifndef WAGON_H_INCLUDED
#define WAGON_H_INCLUDED
#pragma once
using namespace std;

enum trainPath {Depo, Left, Right};

class Wagon
{
public:
    Wagon():path(Depo){}
    trainPath path;
};

#endif
