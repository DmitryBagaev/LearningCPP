//----------------------------------------------------------------------------------
/*
Наследование
Создать абстрактный класс CVehicle. На его основе реализовать классы CPlane,
ССаг и CShip. Классы должны иметь возможность задавать и получать коорди­
наты, параметры средств передвижения (цена, скорость, год выпуска). Для само­
лета должна быть определена высота, для самолета и корабля — количество пас­
сажиров. Для корабля — порт приписки.
Программа должна содержать меню, позволяющее осуществить провер­
ку всех методов классов.
*/
//----------------------------------------------------------------------------------
#include <iostream>
#include <cship.h>
#include <ccar.h>
#include <cplane.h>
#include <cvehicle.h>

int main()
{
    CCar car;
    CPlane plane;
    CShip ship;
/*
    string inputS;
    int inputI;

    cout << "To verify methods input: 1 for car, 2 for plane, 3 for ship" << endl << "Input: ";
    cin >> inputI;
    switch (inputI) {
    case 1:
        cout << "Car" << endl;
        cout << "Input position: " << endl << "X = ";
        cin >> inputI;
        car.setX(inputI);
        cout << "Y = ";
        cin >> inputI;
        car.setY(inputI);
        cout << "Input price: ";
        cin >> inputI;
        car.setPrice(inputI);
        cout << "Input speed: ";
        cin >> inputI;
        car.setSpeed(inputI);
        cout << "Input year of manufacture: ";
        cin >> inputI;
        car.setCreationTime(inputI);
        cout << "Position: " << car.getX() << " - " << car.getY() << endl
             << "Price: " << car.getPrice() << endl
             << "Speed " << car.getSpeed() << endl
             << "Year of manifacture: " << car.getCreationTime() << endl;
        break;
    case 2:
        cout << "Plane" << endl;
        cout << "Input position: " << endl << "X = ";
        cin >> inputI;
        plane.setX(inputI);
        cout << "Y = ";
        cin >> inputI;
        plane.setY(inputI);
        cout << "Input price: ";
        cin >> inputI;
        plane.setPrice(inputI);
        cout << "Input speed: ";
        cin >> inputI;
        plane.setSpeed(inputI);
        cout << "Input year of manufacture: ";
        cin >> inputI;
        plane.setCreationTime(inputI);
        cout << "Input number of passangers: ";
        cin >> inputI;
        plane.setPassangers(inputI);
        cout << "Input plane height: ";
        cin >> inputI;
        plane.setHeight(inputI);
        cout << "Position: " << plane.getX() << " - " << plane.getY() << endl
             << "Price: " << plane.getPrice() << endl
             << "Speed " << plane.getSpeed() << endl
             << "Year of manifacture: " << plane.getCreationTime() << endl
             << "Number of passangers: " << plane.getPassangers() << endl
             << "Plane height: " << plane.getHeight() << endl;
        break;
    case 3:
        cout << "Ship" << endl;
        cout << "Input position: " << endl << "X = ";
        cin >> inputI;
        ship.setX(inputI);
        cout << "Y = ";
        cin >> inputI;
        ship.setY(inputI);
        cout << "Input price: ";
        cin >> inputI;
        ship.setPrice(inputI);
        cout << "Input speed: ";
        cin >> inputI;
        ship.setSpeed(inputI);
        cout << "Input year of manufacture: ";
        cin >> inputI;
        ship.setCreationTime(inputI);
        cout << "Input number of passangers: ";
        cin >> inputI;
        ship.setPassangers(inputI);
        cout << "Input direction: ";
        cin >> inputS;
        ship.setDirection(inputS);
        cout << "Position: " << ship.getX() << " - " << ship.getY() << endl
             << "Price: " << ship.getPrice() << endl
             << "Speed " << ship.getSpeed() << endl
             << "Year of manifacture: " << ship.getCreationTime() << endl
             << "Number of passangers: " << ship.getPassangers() << endl
             << "Direction: " << ship.getDirection() << endl;
        break;

    default:
        cout << "Wrong input" << endl;
        break;
    }
*/

    CVehicle *Vehicle = new CVehicle();
    CVehicle *Ship = new CShip();
    Vehicle->getX();
    Vehicle->getY();
    Ship->getX();
    Ship->getY();

    return 0;
}
