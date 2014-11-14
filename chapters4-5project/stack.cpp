#include "stack.h"

template <class T>
Stack <T>::Stack(): size(0), content(size), top(0) { }

template <class T>
Stack <T>::Stack(int stackSize): size(stackSize), content(size), top(0) { }

template <class T>
T Stack <T>::pop()
{
    T h = content[--top];;
    content.pop_back();
    return h;
}

template <class T>
void Stack <T>::push(T wag)
{
    top++;
    content.push_back(wag);

}

template <class T>
int Stack <T>::getTop()
{
    return top;
}
