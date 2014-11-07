#include <iostream>
#include <vector>
#include <time.h>
#include <list>
#include <deque>
#include <set>
#include <map>

const long n=10000000;

using namespace std;

long timeReturn(long timeEnd, long timeStart);
template <typename T> long creating(T &container);
template <typename T> long creatingMap(T &container);
template <typename T> long creatingSet(T &container);
template <typename T> long deletingEnd(T& container);
template <typename T> long addingEnd(T& container);
template <typename T> long deletingFront(T& container);
template <typename T> long addingFront(T& container);
template <typename T> long findingElement(T& container);
template <typename T> long erasingElement(T &container);
template <typename T> long insertingElement(T& container, long position);
template <typename T> long insertingElementSet(T& container, long position);

int main()
{
    vector <long> testVector;
    cout << "Vector:\n";

    creating(testVector);
    deletingEnd(testVector);
    addingEnd(testVector);

    list <long> testList;
    cout << "\nList:\n";

    creating(testList);
    deletingEnd(testList);
    addingEnd(testList);
    deletingFront(testList);

    deque <long> testDeque;
    cout << "\nDeque:\n";

    creating(testDeque);
    deletingEnd(testDeque);
    addingEnd(testDeque);
    deletingFront(testDeque);
    addingFront(testDeque);

    map<long,long> testMap;
    cout << "\nMap:\n";

    creatingMap(testMap);
    findingElement(testMap);
    erasingElement(testMap);
    insertingElement(testMap,n/2+1);
    insertingElement(testMap,1);
    insertingElement(testMap,n-1);

    set<long> testSet;
    cout << "\nSet:\n";

    creatingSet(testSet);
    findingElement(testSet);
    erasingElement(testSet);
    insertingElementSet(testSet,n/2+1);
    insertingElementSet(testSet,1);
    insertingElementSet(testSet,n-1);

    return 0;
}

template <typename T> long creating(T &container)
{
    long timeStart = clock();
    for (int i = 0; i < n; ++i )
        container.push_back(i);
    long timeEnd = clock();
    cout << "Creating time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return 0;
}

template <typename T> long creatingMap(T &container)
{
    long timeStart = clock();
    for (int i = 0; i < n; ++i )
        container.insert ( pair<long,long>(2*i,i) );
    long timeEnd = clock();
    cout << "Creating time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return 0;
}

template <typename T> long creatingSet(T &container)
{
    long timeStart = clock();
    for (int i = 0; i < n; ++i )
        container.insert(i);
    long timeEnd = clock();
    cout << "Creating time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return 0;
}

template <typename T> long deletingEnd(T &container)
{
    long timeStart = clock();
    container.pop_back();
    long timeEnd = clock();
    cout << "Deleting last element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

template <typename T> long addingEnd(T &container)
{
    long timeStart = clock();
    container.push_back(999999);
    long timeEnd = clock();
    cout << "Adding last element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

template <typename T> long deletingFront(T &container)
{
    long timeStart = clock();
    container.pop_front();
    long timeEnd = clock();
     cout << "Deleting first element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

template <typename T> long addingFront(T &container)
{
    long timeStart = clock();
    container.push_front(1);
    long timeEnd = clock();
    cout << "Adding first element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

template <typename T> long findingElement(T &container)
{
    long timeStart = clock();
    container.find (n/2);
    long timeEnd = clock();
    cout << "Finding element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

template <typename T> long erasingElement(T &container)
{
    long timeStart = clock();
    container.erase (n/2);
    long timeEnd = clock();
    cout << "Erasing element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return 0;
}

template <typename T> long insertingElement(T &container, long position)
{
    long timeStart = clock();
    container.insert (pair<long,long>(position,n/2));
    long timeEnd = clock();
    cout << "Inserting element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

template <typename T> long insertingElementSet(T &container, long position)
{
    long timeStart = clock();
    container.insert (position);
    long timeEnd = clock();
    cout << "Inserting element time: " << timeReturn(timeEnd, timeStart) << " mu\n";
    return timeEnd - timeStart;
}

long timeReturn(long timeEnd, long timeStart)
{
    return 1000000*(timeEnd-timeStart)/CLOCKS_PER_SEC;
}
