#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

bool linearSearchUnsorted(vector<int> &data, int value) 
{
	int size = data.size();
	for (int i = 0; i < size; i++)
	{
		if (value == data[i])
		{
			return true;
		}
	}
	return false; 
}

bool linearSearchSorted(vector<int> &data, int value) 
{
	int size = data.size();
	for (int i = 0; i < size; i++)
	{
		if (value == data[i])
		{
			return true;
		}
		else if	(value < data[i])
		{
			return false;
		}
	}
	return false; 
}

int SequentialSearch(vector<int> &arr, int value) 
{
	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		if (value == arr[i])
		return i;
	}
	return -1; 
}

bool BinarySearchRecursive(vector<int> &data, int low, int high, int value) 
{
	if (low > high)
	{
		return false;
	}
	int mid = low + (high - low) / 2; // To avoid the overflow                   
	if (data[mid] == value)
	{
		return true;
	}
	else if (data[mid] < value)
	{
		return BinarySearchRecursive(data, mid + 1, high, value);
	}
	else
	{
		return BinarySearchRecursive(data, low, mid - 1, value);
	} 
}

int BinarySearch(vector<int> &arr,int value) 
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
