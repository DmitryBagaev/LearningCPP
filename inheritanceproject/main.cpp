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

    string s;

    int h;
    cout << "To verify methods input: 1 for car, 2 for plane, 3 for ship" << endl << "Input: ";
    cin >> h;
    switch (h) {
    case 1:
        cout << "Car" << endl;
        cout << "Input position: " << endl << "X = ";
        cin >> h;
        car.setPositionX(h);
        cout << "Y = ";
        cin >> h;
        car.setPositionY(h);
        cout << "Input price: ";
        cin >> h;
        car.setPrice(h);
        cout << "Input speed: ";
        cin >> h;
        car.setSpeed(h);
        cout << "Input year of manufacture: ";
        cin >> h;
        car.setCreationTime(h);
        cout << "Position: " << car.getPositionX() << " - " << car.getPositionY() << endl
             << "Price: " << car.getPrice() << endl
             << "Speed " << car.getSpeed() << endl
             << "Year of manifacture: " << car.getCreationTime() << endl;
        break;
    case 2:
        cout << "Plane" << endl;
        cout << "Input position: " << endl << "X = ";
        cin >> h;
        plane.setPositionX(h);
        cout << "Y = ";
        cin >> h;
        plane.setPositionY(h);
        cout << "Input price: ";
        cin >> h;
        plane.setPrice(h);
        cout << "Input speed: ";
        cin >> h;
        plane.setSpeed(h);
        cout << "Input year of manufacture: ";
        cin >> h;
        plane.setCreationTime(h);
        cout << "Input number of passangers: ";
        cin >> h;
        plane.setPassangers(h);
        cout << "Input plane height: ";
        cin >> h;
        plane.setHeight(h);
        cout << "Position: " << plane.getPositionX() << " - " << plane.getPositionY() << endl
             << "Price: " << plane.getPrice() << endl
             << "Speed " << plane.getSpeed() << endl
             << "Year of manifacture: " << plane.getCreationTime() << endl
             << "Number of passangers: " << plane.getPassangers() << endl
             << "Plane height: " << plane.getHeight() << endl;
        break;
    case 3:
        cout << "Ship" << endl;
        cout << "Input position: " << endl << "X = ";
        cin >> h;
        ship.setPositionX(h);
        cout << "Y = ";
        cin >> h;
        ship.setPositionY(h);
        cout << "Input price: ";
        cin >> h;
        ship.setPrice(h);
        cout << "Input speed: ";
        cin >> h;
        ship.setSpeed(h);
        cout << "Input year of manufacture: ";
        cin >> h;
        ship.setCreationTime(h);
        cout << "Input number of passangers: ";
        cin >> h;
        ship.setPassangers(h);
        cout << "Input direction: ";
        cin >> s;
        ship.setDirection(s);
        cout << "Position: " << ship.getPositionX() << " - " << ship.getPositionY() << endl
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

    return 0;
}
