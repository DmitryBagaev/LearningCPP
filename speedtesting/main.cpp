#include <iostream>
#include <vector>
#include <time.h>
#include <list>
#include <deque>

const long n=100000;

using namespace std;

template <typename T> int creating(T container);
template <typename T> int deletingEnd(T container);
template <typename T> int addingEnd(T container);

int main()
{
    vector <int> testVector(n);
    //    vector< int >::iterator it;
    cout << "Vector:\n";

    cout << "Creating time: " << creating(testVector) << " mcs\n";
    cout << "Deleting last element time: " << deletingEnd(testVector) << " mcs\n";
    cout << "Adding last element time: " << addingEnd(testVector) << " mcs\n";

    list <int> testList(n);
    cout << "\nList:\n";

//cout << "Creating time: " << creating(testList) << " mcs\n";
    cout << "Deleting last element time: " << deletingEnd(testList) << " mcs\n";
    cout << "Adding last element time: " << addingEnd(testList) << " mcs\n";

    deque <int> testDeque(n);
    cout << "\nDeque:\n";

cout << "Creating time: " << creating(testDeque) << " mcs\n";
    cout << "Deleting last element time: " << deletingEnd(testDeque) << " mcs\n";

    cout << "Adding last element time: " << addingEnd(testDeque) << " mcs\n";

    return 0;
}

template <typename T> int creating(T container)
{
    long timeStart = clock();
   for (int i = 0; i<n; i++ ) { container[i] = i; }
    long timeEnd = clock();
    return timeEnd - timeStart;
}

template <typename T> int deletingEnd(T container)
{
long timeStart = clock();
container.pop_back();
long timeEnd = clock();
return timeEnd - timeStart;
}

template <typename T> int addingEnd(T container)
{
long timeStart = clock();
container.push_back(999999);
long timeEnd = clock();
return timeEnd - timeStart;
}
