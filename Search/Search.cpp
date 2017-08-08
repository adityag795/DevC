#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

int SequentialSearch(std:: vector<int> &arr, int value) 
{
	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		if (value == arr[i])
		return i;
	}
	return -1; 
}

int BinarySearch(std::vector<int> &arr,int value) 
{ 
	int size = arr.size();
	int mid;
	int low = 0;
	int high = size-1;
	while (low <= high)
	{ 
		mid = low + (high - low) / 2; // To avoid the overflow
		if (arr[mid] == value)
		{
			return mid;
		}
		else
		{
			if (arr[mid] < value)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return -1; 
}

int main()
{
	vector<int> arr = {12,34,56,84,29,98,75,5};
	cout<<"Enter the element to searched: ";
	int val;
	cin>>val;

	cout<<"\n1.Sequential Search";
	cout<<"\n2.Binary Search";
	cout<<"\nChoose the type of search: ";

	int ch;
	cin>>ch;
	switch(ch)
	{	
		int pos;
		case 1:
			pos = SequentialSearch(arr,val);
			if (pos == -1)
				cout<<"\nValue not found.";
			else
				cout<<"\nValue found at position "<<pos;
			break;
		case 2:
			pos = BinarySearch(arr,val);
			if (pos == -1)
				cout<<"\nValue not found.";
			else
				cout<<"\nValue found at position "<<pos;
			break;
		default:cout<<"Enter correct choice (1 or 2): ";
	}

	return 0;
}