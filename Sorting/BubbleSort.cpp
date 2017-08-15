#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

class BubbleSort 
{
	private:
		vector<int> &arr;
		bool less(int value1, int value2);
		bool more(int value1, int value2); 
	
	public:
	    BubbleSort(vector<int> &data);
        virtual void sort1();
        virtual void sort2(); 
};

BubbleSort::BubbleSort(vector<int> &data):arr(data) { }
/* 
You can't initialize reference members as shown below.
You must use initializer's list.
BubbleSort::BubbleSort(vector<int> &data)
{
    arr = data;
}
Also, for performance reasons, It is better to initialize all class variables in Initializer List 
instead of assigning values inside body. 
*/
bool BubbleSort::less(int value1, int value2) 
{
	return value1 < value2; 
} 

bool BubbleSort::more(int value1, int value2) 
{
	return value1 > value2; 
}

// Bubble Sort
void BubbleSort::sort1() 
{
	int size = arr.size();
	int i, j, temp;
	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (more(arr[j],arr[j + 1]))
			{        
				/* Swapping */        
				temp = arr[j];        
				arr[j] = arr[j + 1];        
				arr[j + 1] = temp;
			}        
		}
	} 
} 
// Modified Bubble Sort with best case O(n)
void BubbleSort::sort2() 
{
	int size = arr.size();
	int i, j, temp, swapped = 1;
	for (i = 0; i < (size - 1) && swapped == 1; i++)
	{         
		swapped = 0;       
		for (j = 0; j < size-i-1; j++)         
		{         
			if (more(arr[j],arr[j+1]))         
			{        
				temp = arr[j];        
				arr[j] = arr[j + 1];        
				arr[j + 1] = temp;        
				swapped = 1;         
			}         
		}
	} 
}

int main() 
{
	vector<int> data = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	BubbleSort *bs = new BubbleSort(data);
	bs-> sort2();
	for (int i = 0; i < data.size(); i++)
	    cout << data[i] << " ";
	return 0; 
}