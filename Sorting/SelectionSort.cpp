#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

class SelectionSort 
{ 
	private:
		vector<int> &arr;
		bool less(int value1, int value2);
		bool more(int value1, int value2); 
		void swap(int&, int&);
	public:
		SelectionSort(vector<int> &data);
		virtual void sort(); // back array
		virtual void sort2(); // front array 
}; 

SelectionSort:: SelectionSort(vector<int> &data):arr( data) { } 

bool SelectionSort:: less( int value1, int value2) 
{
	return value1 < value2; 
} 

bool SelectionSort:: more( int value1, int value2) 
{
	return value1 > value2;
} 

void SelectionSort::swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

// Please follow the next method.
void SelectionSort:: sort() 
{
	int size = arr.size();
	int i, j, max;
	for (i = 0; i < size-1; i++)
	{
		max = 0;
		for (j = 1; j < size-1-i; j++)
		{
			if (arr[j] > arr[max])
			{        
				max = j;
			}
		}
		swap(arr[size-1-i],arr[max]);
	} 
}

// This is more prefferable as it can converted for descending order by changing if condition
// by changing '<' to ' >'.
void SelectionSort:: sort2()
{
	int size = arr.size();          
	int i, j, min;          
	for (i = 0; i < size-1; i++)          
	{                   
		min = i;                   
		for (j = i + 1; j < size; j++)                   
		{                             
			if (arr[j] < arr[min])                             
			{                                      
				min = j;                             
			}                   
		}
		swap(arr[i],arr[min]);
	} 
}

int main() 
{
	vector<int> data = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	SelectionSort *bs = new SelectionSort(data);
	bs -> sort2();
	for (int i = 0; i < data.size(); i++)
    	cout << data[i] << " ";
	return 0; 
}