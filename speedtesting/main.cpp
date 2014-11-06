#include <iostream>
#include <vector>
#include <time.h>
#include <list>
#include <deque>

const long n=10000000;

using namespace std;

long timeReturn(long timeEnd, long timeStart);
template <typename T> long creating(T container);
template <typename T> long deletingEnd(T container);
template <typename T> long addingEnd(T container);
template <typename T> long deletingFront(T container);
template <typename T> long addingFront(T container);

int main()
{
    vector <long> testVector(n);
    cout << "Vector:\n";

    creating(testVector);
    deletingEnd(testVector);
    addingEnd(testVector);

    /*    list <long> testList(n);
cout << "\nList:\n";

//creating(testList);
deletingEnd(testList);
addingEnd(testList);
*/
    deque <long> testDeque(n);
    cout << "\nDeque:\n";

    creating(testDeque);
    deletingEnd(testDeque);
    addingEnd(testDeque);
    deletingFront(testDeque);
    addingFront(testDeque);

    return 0;
}

template <typename T> long creating(T container)
{
    long timeStart = clock();
    for (int i = 0; i<n; i++ )
        container[i] = i;
    long timeEnd = clock();
    cout << "Creating time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

template <typename T> long deletingEnd(T container)
{
    long timeStart = clock();
    container.pop_back();
    long timeEnd = clock();
    cout << "Deleting last element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

template <typename T> long addingEnd(T container)
{
    long timeStart = clock();
    container.push_back(999999);
    long timeEnd = clock();
    cout << "Adding last element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

template <typename T> long deletingFront(T container)
{
    long timeStart = clock();
    container.pop_front();
    long timeEnd = clock();
    cout << "Deleting first element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

template <typename T> long addingFront(T container)
{
    long timeStart = clock();
    container.push_front(1);
    long timeEnd = clock();
    cout << "Adding first element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

long timeReturn(long timeEnd, long timeStart)
{
    return 1000000*(timeEnd-timeStart)/CLOCKS_PER_SEC;

}
