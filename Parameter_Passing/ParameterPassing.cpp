#include <iostream>

using namespace std;

void incrementPassByValue(int var)
{
    var++;
}

void incrementPassByReference(int &var)
{
    var++;
}

void incrementPassByPointer(int *ptr) 
{
    (*ptr)++;
}

int main()
{
    int i = 10;
    int ch;
    cout << "1. Pass by Value.\n";
    cout << "2. Pass by Reference.\n";
    cout << "3. Call by Pointer\n";
    cout << "Enter your choice (1,2,3): ";
    cin>>ch;

    switch (ch)
    {
        case 1:
            cout << "\nValue of i before increment is :" << i << endl;
            incrementPassByValue(i);
            cout << "\nValue of i after increment is :" << i << endl;
            break;
        case 2:
            cout << "\nValue of i before increment is :" << i << endl;
            incrementPassByReference(i);
            cout << "\nValue of i after increment is :" << i << endl;
            break;
        case 3:
            cout << "\nValue of i before increment is :" << i << endl;
            incrementPassByPointer(&i);
            cout << "\nValue of i after increment is :" << i << endl;
            break;
        default:cout<<"\nEnter right choice(1,2,3).";
    }
}