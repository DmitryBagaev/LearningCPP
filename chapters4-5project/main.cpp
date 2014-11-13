//-------------------------------------------------
/*
Классы
Вариант 1
Описать класс, реализующий стек. Написать программу, использующую этот
класс для моделирования Т-образного сортировочного узла на железной дороге.
Программа должна разделять на два направления состав, состоящий из вагонов
двух типов (на каждое направление формируется состав из вагонов одного типа).
Предусмотреть возможность формирования состава с клавиатуры.
*/
//-------------------------------------------------

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

enum trainPath {Left = 1, Right};

class Train
{
public:
    Train():trainDirection(0),top(0){ }
    vector<trainPath> trainDirection;
    int top;
};

class Stack
{
public:
    Stack(int& stackSize): content(stackSize), top(0) { }
private:
    vector <trainPath> content;
    int top;
public:
    void push(trainPath &wag);
    void pop(Train& leftTrain, Train& rightTrain);
    void show();
    int getTop();
};


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
    content[top++] = wag;
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

int main()
{
    srand(time(nullptr));

    int stackSize;
    cout << "Stacksize: ";
    cin >> stackSize;
    cout << endl;

    Stack st(stackSize);
    trainPath rPush;
    for (int i = 0; i < stackSize; i++)
    {
        rPush = (trainPath)(rand() % 2 + 1);
        st.push(rPush);
    }

    st.show();

    Train trainLeft;
    Train trainRight;

    for (int i = 0; i < stackSize; i++)
    {
        st.pop(trainLeft,trainRight);
    }

    cout << "Left content:" << endl;
    int h = trainLeft.trainDirection.size();
    for (int i = 0; i < h; i++)
        cout << trainLeft.trainDirection[i] << " ";
    cout << endl;

    cout << "Right content:" << endl;
    h = trainRight.trainDirection.size();
    for (int i = 0; i < h; i++)
        cout << trainRight.trainDirection[i] << " ";
    cout << endl;

    return 1;
}
