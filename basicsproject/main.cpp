#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "secondtask.cpp"

using namespace std;

void oneDimension(int size);
void twoDimensionsWithPointers(int size);
void trainStructure(int trainAmount);
template <class T> void betweenAB(T arr, int size, int begin, int end);
template <class T> void afterMax(T arr, int size);
template <class T> void sort (T arr, int size);

int main()
{
    //oneDimension(15);
    twoDimensionsWithPointers(10);
    //trainStructure(6);
    return 0;
}

void trainStructure(int trainAmount)
{
    struct Train{
        string direction;
        int number;
        string time;
    };

    Train trainArr[trainAmount];

    for (int i = 0; i < trainAmount; i++)
    {
        cout << endl << "Input direction of " << i << "train: ";
        cin >> trainArr[i].direction;
        cout << endl << "Input it's number: ";
        cin >> trainArr[i].number;
        cout << endl << "Input hour of departure: ";
        cin >> trainArr[i].time;
    }

    int trainCounter = 0;
    string trainDirection;
    cout << endl << "Input your direction:";
    cin >> trainDirection;
    for (int i = 0; i < trainAmount; i++)
        if (trainDirection == trainArr[i].direction){
            trainCounter++;
            cout << endl << "Direction: " << trainArr[i].direction << endl
                 << "Number: " << trainArr[i].number << endl
                 << "Hour of departure: " << trainArr[i].time << endl;
        }
    if (!trainCounter)
        cout << endl << "There's no train with this direction" << endl;
}


void twoDimensionsWithPointers(int size)
{
    srand(time(nullptr));

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

    cout << "Array:" << endl;

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
            if ((arr[i][j] < arr[i][j+1]) && (arr[i][j] < arr[i][j-1]) && (arr[i][j] < arr[i+1][j]) && (arr[i][j] < arr[i-1][j]))
            {
                counter += 1 ;
            }
        }
    }

    cout << "Amount of \"weak\" elements: " << counter << endl;

    int sum = 0;
    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 1; j < size + 1; j++){
            if (j > i)
                sum += arr[i][j];
        }
    }
    cout << "Sum of elements above the main diagonal: " << sum << endl;

    for (int i = 0; i < size + 2; i++)
        delete arr[i];
    delete[] arr;
}

void oneDimension(int size)
{
    cout << "Size of array is : " << size << endl;

    srand(time(nullptr));

    double arrDouble[size];
    float arrFloat[size];
    int arrInt[size];

    for (int i = 0; i < size; i++)
        arrDouble[i] = 0.02 * ( rand() % 10000 )- 100;
    //cout << "Array of random elements from 1 to 100:" << endl;
    //for (int i = 0; i < size; i++)
    //  cout << arr[i] << " ";
    //cout << endl;

    for (int i = 0; i < size; i++)
        arrFloat[i] = 0.02 * ( rand() % 10000 )- 100;

    for (int i = 0; i < size; i++)
        arrInt[i] = 2 * rand() % 100 - 100;

    int a = 5;
    int b = 10;

    betweenAB(arrDouble, size, a, b);
    afterMax(arrFloat, size);
    sort (arrInt, size);
}

template <class T> void betweenAB(T arr, int size, int begin, int end)
{
    cout << "Elements between " << begin << " and " << end << endl;
    if ((begin >=0)&&(end<=size))
        for (int i = begin; i < end-1; i++)
            cout << arr[i] << " ";
    else
        cout << "Wrong parametrs of between function";
    cout << endl;
}


template <class T> void afterMax(T arr, int size)
{
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
    for (int i = maxPos+1; i < size; i++)
        sum += arr[i];
    cout << "Sum of the elements after max:" << sum << endl;
}

template <class T> void sort (T arr, int size)
{
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size ; ++j)
            if ( fabs(arr[j]) > fabs(arr[i]) )
                swap( arr[i], arr[j] );

    cout << "Sorted abs-s in descending order:" << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
