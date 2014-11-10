#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int oneDimention();
int twoDimentionsWithPointers();
int trainStructure();

int main()
{
    //    oneDimention();
    //twoDimentionsWithPointers();
    trainStructure();
    return 0;
}

int trainStructure()
{
    struct Train{
        string direction;
        int number;
        string time;
    };

    int trainAmount = 6;
    Train trainArr[trainAmount];

    for (int i = 0; i < trainAmount; i++)
    {
        cout << endl << "Введите пункт назначения " << i << "-ого поезда: ";
        cin >> trainArr[i].direction;
        cout << endl << "Введите его номер: ";
        cin >> trainArr[i].number;
        cout << endl << "Введите час отправления: ";
        cin >> trainArr[i].time;
    }

    int trainCounter = 0;
    string trainDirection;
    cout << endl << "Введите искомый пункт назначения:";
    cin >> trainDirection;
     for (int i = 0; i < trainAmount; i++)
         if (trainDirection == trainArr[i].direction){
             trainCounter++;
            cout << endl << "Пункт назначения: " << trainArr[i].direction << endl
                    << "Номер: " << trainArr[i].number << endl
                       << "Час отправления: " << trainArr[i].time << endl << endl;
         }
    if (trainCounter == 0)
        cout << endl << "Таких поездов нет" << endl;

    return 0;
}


int twoDimentionsWithPointers()
{
        srand(time(NULL));

    int size = 10;
    int **arr = new int *[size + 2];
    for (int i = 0; i < size + 2; i++)
        arr[i] = new int [size + 2];

    for (int i = 0; i < size + 2; i++)
    {
        for (int j = 0; j < size + 2; j++){
            if ((i == 0) | (j == 0) | (i == size + 1) | (j == size + 1))
                arr[i][j] = 10000;
        }
    }

    cout << "Массив:" << endl;

    for (int i = 1; i < size+1; i++)
    {
        for (int j = 1; j < size + 1; j++){
            arr[i][j] =  rand() % 100;
            cout << arr [i][j] << " ";
        }
        cout << endl;
    }

    int counter = 0;

    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 1; j < size + 1; j++){
            if ((arr[i][j] < arr[i][j+1]) & (arr[i][j] < arr[i][j-1]) & (arr[i][j] < arr[i+1][j]) & (arr[i][j] < arr[i-1][j]))
            {
                counter += 1 ;
            }
        }
    }

    cout << "Число \"слабых\" элементов: " << counter << endl;

    int sum = 0;
    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 1; j < size + 1; j++){
            if (j > i)
                sum += arr[i][j];
        }
    }
    cout << "Сумма элементов выше главной диагонали: " << sum << endl;

    return 0;
}

int oneDimention()
{
    int size = 15;
    cout << "Size of array is : " << size << endl;

    srand(time(NULL));

    double arr[size];

    for (int i = 0; i < size; i++)
        arr[i] = 0.02 * ( rand() % 10000 )- 100;
    cout << "Массив случайных элементов от 1 до 100:" << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int a = 5;
    int b = 10;

    cout << "Вывод элементов между " << a << " и " << b << endl;
    for (int i = a; i < b-1; i++)
        cout << arr[i] << " ";
    cout << endl;

    double max = arr[0];
    int maxPos = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            maxPos = i;
        }
    }

    double sum = 0;
    for (int i = maxPos+1; i < size; i++) sum += arr[i];
    cout << "Сумма элементов после максимального равна:" << sum << endl;

    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size ; ++j)
            if ( fabs(arr[j]) > fabs(arr[i]) ) swap( arr[i], arr[j] );

    cout << "Отсортированный по убыванию массив:" << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
