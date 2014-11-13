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
#include "stack.h"

int main()
{
    srand(time(nullptr));

    int stackSize;
    cout << "Stacksize: ";
    cin >> stackSize;
    cout << endl;

    Stack st;
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
