#ifndef WAGON_H_INCLUDED
#define WAGON_H_INCLUDED
#pragma once
using namespace std;

enum trainPath {Left = 1, Right};

class Wagon
{
public:
    trainPath path;
};

#endif
