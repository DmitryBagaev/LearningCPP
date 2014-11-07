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
template <typename T> long creating(T container);
template <typename T> long deletingEnd(T container);
template <typename T> long addingEnd(T container);
template <typename T> long deletingFront(T container);
template <typename T> long addingFront(T container);
template <typename T> long findingElement(T container);
template <typename T> long erasingElement(T container);
template <typename T> long insertingElement(T container, int position);
template <typename T> long insertingElementSet(T container, int position);

int main()
{
    vector <long> testVector;
    cout << "Vector:\n";

    long timeStart = clock();
    for (int i = 0; i < n; ++i )
        testVector.push_back(i);
    long timeEnd = clock();
    cout << "Creating time: " << timeReturn(timeEnd, timeStart) << " ms\n";

    //    cout << testVector.size() << "\n";
    deletingEnd(testVector);
    addingEnd(testVector);

    list <long> testList;
    cout << "\nList:\n";

    timeStart = clock();
    for (int i = 0; i < n; ++i )
        testList.push_back(i);
    timeEnd = clock();
    cout << "Creating time: " << timeReturn(timeEnd, timeStart) << " ms\n";

    //    cout << testList.size() << "\n";
    deletingEnd(testList);
    addingEnd(testList);
    deletingFront(testList);

    deque <long> testDeque;
    cout << "\nDeque:\n";

    timeStart = clock();
    for (int i = 0; i < n; ++i )
        testDeque.push_back(i);
    timeEnd = clock();
    cout << "Creating time: " << timeReturn(timeEnd, timeStart) << " ms\n";

    //    cout << testDeque.size() << "\n";
    deletingEnd(testDeque);
    addingEnd(testDeque);
    deletingFront(testDeque);
    addingFront(testDeque);

    map<long,long> testMap;
    cout << "\nMap:\n";

    timeStart = clock();
    for (int i = 0; i < n; ++i )
        testMap.insert ( pair<long,long>(2*i,i) );
    timeEnd = clock();
    cout << "Creating time: " << timeReturn(timeEnd, timeStart) << " ms\n";

    //    cout << testMap.size() << "\n";
    findingElement(testMap);
    erasingElement(testMap);
    insertingElement(testMap,5000001);
    insertingElement(testMap,1);
    insertingElement(testMap,9999999);

    set<long> testSet;
    cout << "\nSet:\n";
    timeStart = clock();
    for (int i = 0; i < n; ++i )
        testSet.insert(i);
    timeEnd = clock();
    cout << "Creating time: " << timeReturn(timeEnd, timeStart) << " ms\n";

    //    cout << testSet.size() << "\n";
    findingElement(testSet);
    erasingElement(testSet);
    insertingElementSet(testSet,5000001);
    insertingElementSet(testSet,1);
    insertingElementSet(testSet,9999999);

    return 0;
}

template <typename T> long creating(T container)
{
    long timeStart = clock();
    for (int i = 0; i < n; ++i )
        container.push_back(i);
    long timeEnd = clock();
    cout << "Creating time: " << timeReturn(timeEnd, timeStart) << " ms\n";
    return 0;
}

template <typename T> long deletingEnd(T container)
{
    long timeStart = clock();
    container.pop_back();
    long timeEnd = clock();
    cout << "Deleting last element time: " << timeReturn(timeEnd, timeStart) << " ms\n";
    return timeEnd - timeStart;
}

template <typename T> long addingEnd(T container)
{
    long timeStart = clock();
    container.push_back(999999);
    long timeEnd = clock();
    cout << "Adding last element time: " << timeReturn(timeEnd, timeStart) << " ms\n";
    return timeEnd - timeStart;
}

template <typename T> long deletingFront(T container)
{
    long timeStart = clock();
    container.pop_front();
    long timeEnd = clock();
    cout << "Deleting first element time: " << timeReturn(timeEnd, timeStart) << " ms\n";
    return timeEnd - timeStart;
}

template <typename T> long addingFront(T container)
{
    long timeStart = clock();
    container.push_front(1);
    long timeEnd = clock();
    cout << "Adding first element time: " << timeReturn(timeEnd, timeStart) << " ms\n";
    return timeEnd - timeStart;
}

template <typename T> long findingElement(T container)
{
    long timeStart = clock();
    container.find (2500000);
    long timeEnd = clock();
    cout << "Finding element time: " << timeReturn(timeEnd, timeStart) << " ms\n";
    return timeEnd - timeStart;
}

template <typename T> long erasingElement(T container)
{
    long timeStart = clock();
    container.erase (2500000);
    long timeEnd = clock();
    cout << "Erasing element time: " << timeReturn(timeEnd, timeStart) << " ms\n";
    return timeEnd - timeStart;
}

template <typename T> long insertingElement(T container, int position)
{
    long timeStart = clock();
    container.insert (pair<long,long>(position,2500000));
    long timeEnd = clock();
    cout << "Inserting element time: " << timeReturn(timeEnd, timeStart) << " ms\n";
    return timeEnd - timeStart;
}

template <typename T> long insertingElementSet(T container, int position)
{
    long timeStart = clock();
    container.insert (position);
    long timeEnd = clock();
    cout << "Inserting element time: " << timeReturn(timeEnd, timeStart) << " ms\n";
    return timeEnd - timeStart;
}

long timeReturn(long timeEnd, long timeStart)
{
    return 1000*(timeEnd-timeStart)/CLOCKS_PER_SEC;
}
