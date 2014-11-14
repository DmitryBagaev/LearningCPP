#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Stack
{
public:
    Stack();
    Stack(int stackSize);
private:
        int size;
    vector <T> content;
    int top;
public:
    void push(T wag);
    T pop();
    int getTop();
};

#endif
