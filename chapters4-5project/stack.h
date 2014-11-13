#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

enum trainPath {Left = 1, Right};

class Train
{
public:
    Train();
    vector<trainPath> trainDirection;
    int top;
};

class Stack
{
public:
    Stack();
private:
    vector <trainPath> content;
    int top;
public:
    void push(trainPath &wag);
    void pop(Train& leftTrain, Train& rightTrain);
    void show();
    int getTop();
};

#endif
