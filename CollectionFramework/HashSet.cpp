#include<iostream>
#include<conio.h>
#include<functional>
#include<string>
#include<unordered_set> 

using namespace std;


int main() 
{
    // Create a hash set. 
    unordered_set <string> hs;
    // Add elements to the hash set.
    hs.insert("India");
    hs.insert("USA");
    hs.insert("Brazile");
    hs.insert("Canada");
    hs.insert("UK");
    hs.insert("China");
    hs.insert("France");
    hs.insert("Spain");
    hs.insert("Italy");
    for each (auto var in hs)
    {
        cout << var << " ";
    } 
    cout << endl;
    cout << "Hash Table contains USA : " << (find( hs.begin(), hs.end(), "USA") != hs.end()) << endl;
    cout << "Hash Table contains Russia : "<< (find( hs.begin(), hs.end(), "Russia") != hs.end()) << endl;
    hs.erase("USA");
    for each (auto var in hs)
    {
        cout << var <<" ";
    }
    cout << endl;
    cout << "Hash Table contains USA : " << (find( hs.begin(), hs.end(), "USA") != hs.end() )<< endl;
    
    return 0; 
}       
