#include <iostream>
#include <vector>
#include <time.h>
#include <list>
#include <deque>

const long n=10000000;

using namespace std;

template <typename T> long creating(T container);
template <typename T> long deletingEnd(T container);
template <typename T> long addingEnd(T container);
template <typename T> long deletingFront(T container);
template <typename T> long addingFront(T container);

int main()
{
    vector <long> testVector(n);
    //    vector< int >::iterator it;
    cout << "Vector:\n";

    cout << "Creating time: " << creating(testVector) << " mcs\n";
    cout << "Deleting last element time: " << deletingEnd(testVector) << " mcs\n";
    cout << "Adding last element time: " << addingEnd(testVector) << " mcs\n";

    list <long> testList(n);
    cout << "\nList:\n";

    //cout << "Creating time: " << creating(testList) << " mcs\n";
    cout << "Deleting last element time: " << deletingEnd(testList) << " mcs\n";
    cout << "Adding last element time: " << addingEnd(testList) << " mcs\n";

    deque <long> testDeque(n);
    cout << "\nDeque:\n";

    cout << "Creating time: " << creating(testDeque) << " mcs\n";
    cout << "Deleting last element time: " << deletingEnd(testDeque) << " mcs\n";
    cout << "Adding last element time: " << addingEnd(testDeque) << " mcs\n";
    cout << "Deleting first element time: " << deletingFront(testDeque) << " mcs\n";
        cout << "Adding first element time: " << addingFront(testDeque) << " mcs\n";

    return 0;
}

template <typename T> long creating(T container)
{
    long timeStart = clock();
    for (int i = 0; i<n; i++ )
        container[i] = i;
    long timeEnd = clock();
    return timeEnd - timeStart;
}

template <typename T> long deletingEnd(T container)
{
    long timeStart = clock();
    container.pop_back();
    long timeEnd = clock();
    return timeEnd - timeStart;
}

template <typename T> long addingEnd(T container)
{
    long timeStart = clock();
    container.push_back(999999);
    long timeEnd = clock();
    return timeEnd - timeStart;
}

template <typename T> long deletingFront(T container)
{
    long timeStart = clock();
    container.pop_front();
    long timeEnd = clock();
    return timeEnd - timeStart;
}

template <typename T> long addingFront(T container)
{
    long timeStart = clock();
    container.push_front(1);
    long timeEnd = clock();
    return timeEnd - timeStart;
}
