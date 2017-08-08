#include<iostream>
#include<vector>
using namespace std;

int SumArray(vector<int> &arr) 
{
	int size = arr.size();
	int total = 0;
	int index;
	for (index = 0; index < size;index++)
	{
		total = total + arr[index];
	}
	return total; 
} 

int main() 
{
	vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
	cout << "Sum of all the values in array:" << SumArray(arr)<< endl;
	return 0;
}