#include<iostream>
#include<conio.h>
using namespace std;

// Generic Number System Converter
void printInt2(int number, int const base) 
{
	string conversion = "0123456789ABCDEF";
	char digit = static_cast<char>(number % base);
	number = number / base;
	if (number != 0)
	{
		printInt2(number, base);
	}
	cout << " " << conversion[digit]; 
}

int main()
{
	cout<<"Enter the number: ";
	int num;
	cin>>num;

	cout<<"Enter base: ";
	int base;
	cin>>base;

	printInt2(num, base);

	return 0;
}