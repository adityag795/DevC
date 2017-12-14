#include<iostream>
#include<conio.h>
#include<string> //An uninitialized string points to NULL.
using namespace std;

int main()
{
    int i,j,temp;
    //char str[100]={"This is a pattern matching"};
    char str[100];
    //char substr[20]={"pattern"};
    char substr[20];

    cout << "Enter a string: ";
	cin.getline(str,100,'\n');

    cout << "Enter a string you want to find: ";
	cin.getline(substr,20,'\n');

    for(i=0;str[i]!='\0';i++)
    {
        j=0;
        if(str[i]==substr[j])
        {
            temp=i+1;
            while(str[i]==substr[j])
            {
                i++;
                j++;
            }
 
            if(substr[j]=='\0')
            {
                cout<<"The substring is present in given string at position "<<temp<<"\n";
                exit(0);
            }
            else
            {
                i=temp;
                temp=0;
            }
        }
    }

    if(temp==0)
        cout<<"The substring is not present in given string\n";
 
    return 0;
}