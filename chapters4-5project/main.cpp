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
#include <cmath>
#include <vector>
#include "stack.h"
#include "wagon.h"

int main()
{
    srand(time(nullptr));

    int stackSize;
    cout << "Stacksize: ";
    cin >> stackSize;
    cout << endl;
    if (!stackSize)
    {
        cout << "Unvalid input";
    }
    else
    {

        Stack <Wagon> stackDepo;
        vector <Wagon> leftTrain;
        vector <Wagon> rightTrain;

        Wagon wag;

        cout << "Stack content:" << endl;

        for (int i = 0; i < stackSize; i++)
        {

            wag.path = (trainPath)(rand() % 2 + 1);
            stackDepo.push(wag);
            cout << wag.path << " ";
        }
        cout << endl;
        for (int i = 0; i < stackSize; i++)
        {
            wag = stackDepo.pop();

            switch (wag.path) {
            case Left:
                leftTrain.push_back(wag);
                break;
            case Right:
                rightTrain.push_back(wag);
                break;
            default:
                cout << "Mistake!";
                break;
            }
        }
        cout << "Left train" << endl;
        for (int i = leftTrain.size()-1; i >=0; i--)
        {
            cout << leftTrain[i].path << " ";
        }
        cout << endl;

        cout << "Right train" << endl;
        for (int i = rightTrain.size()-1; i >= 0; i--)
        {
            cout << rightTrain[i].path << " ";
        }
        cout << endl;
    }
    return 1;
}
