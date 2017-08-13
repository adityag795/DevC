#include<iostream>
#include<conio.h>
#include<string> //An uninitialized string points to NULL.
using namespace std;

int main()
{
    string str;

    // The most simple way to create string.
    string text = "Hello, World!";

    char arr[] = {'H','e','l','l','o',' ','W','o','r','l','d','!','\0'};
    string hello(arr);

    int len = hello.length();

    cout<<text<<endl<<hello<<"\t"<<len;

    return 0;
}