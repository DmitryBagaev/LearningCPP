#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T> class Stack;

template <class T>
class Stack
{
public:
    Stack();
    Stack(int stackSize);
private:
    int size;
    vector <T> content;
public:
    void push(T wag);
    T pop();
};
template <class T>
Stack <T>::Stack(): size(0), content(size) { }

template <class T>
Stack <T>::Stack(int stackSize): size(stackSize), content(size) { }

template <class T>
T Stack <T>::pop()
{
    T h = content.back();;

    content.pop_back();
    return h;
}

template <class T>
void Stack <T>::push(T wag)
{

    content.push_back(wag);

}

#endif
