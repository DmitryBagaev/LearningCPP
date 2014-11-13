#include <iostream>
#include <vector>
#include "stack.h"

    Train::Train():trainDirection(0),top(0){ }

      Stack::Stack(): content(0), top(0) { }

void Stack::pop(Train& leftTrain, Train& rightTrain)
{
    trainPath tr = content[--top];;
    content.pop_back();
    switch(tr)
    {
    case Left:
        leftTrain.top++;
        leftTrain.trainDirection.push_back(Left);
        break;
    case Right:
        rightTrain.top++;
        rightTrain.trainDirection.push_back(Right);
        break;
    default:
        cout << "Mistake";
        break;
    }
}

void Stack::push(trainPath& wag)
{
top++;
    content.push_back(wag);

}

void Stack::show()
{
    cout << "Stack content:" << endl;
    int h = content.size();
    for (int i = 0; i < h; i++)
        cout << content[i] << " ";
    cout << endl;
}

int Stack::getTop()
{
    return top;
}
