/* Defines the entry point for the console application. */

#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

int main()
{
	/*********************DO WHILE LOOP*************************/
	cout << "DO-WHILE LOOP ";
	vector<int>numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sum = 0;
	int i = 0;
	do
	{
		sum += numbers[i];
		i++;
	} while (i < numbers.size());
	cout << "Sum is :" << sum << endl;

	getch();
	/******************FOR LOOP********************************/
	cout << "FOR LOOP ";

	sum = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		sum += numbers[i];
	}
	cout << "Sum is ::" << sum << endl;
	
	getch();

	/********************FOREACH LOOP***************************/
	numbers = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	cout << "FOREACH LOOP ";

	sum = 0;
	for (auto n : numbers)
	{
		sum += n;
	}
	cout << "Sum is :" << sum << endl;

	return 0;
}