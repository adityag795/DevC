#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

class MergeSort 
{ 
	private:
		vector<int> &arr;
		void merge(vector<int> &arr, vector<int> &tempArray, int lowerIndex, int middleIndex, int upperIndex);
		void mergeSrt(vector<int> &arr, vector<int> &tempArray, int lowerIndex, int upperIndex); 
	public:
		MergeSort(vector<int> &data);
		virtual void sort(); 
}; 

MergeSort::MergeSort(vector<int> &data):arr(data) { } 

void MergeSort:: sort() 
{
	int size = arr.size();
	vector<int> tempArray(size);
	mergeSrt(arr, tempArray, 0, size - 1); 
} 

void MergeSort:: mergeSrt(vector<int> &arr, vector<int> &tempArray, int lowerIndex, int upperIndex) 
{
	if (lowerIndex >= upperIndex)
	{         
		return;
	}
	int middleIndex = (lowerIndex + upperIndex) / 2;
	mergeSrt(arr, tempArray, lowerIndex, middleIndex);
	mergeSrt(arr, tempArray, middleIndex + 1, upperIndex);
	merge(arr, tempArray, lowerIndex, middleIndex, upperIndex); 
} 

void MergeSort:: merge(vector<int> &arr, vector<int> &tempArray, int lowerIndex, int middleIndex, int upperIndex) 
{
	int lowerStart = lowerIndex;
	int lowerStop = middleIndex;
	int upperStart = middleIndex + 1;
	int upperStop = upperIndex;
	int count = lowerIndex;
	while (lowerStart <= lowerStop && upperStart <= upperStop)
	{         
		if (arr[lowerStart] < arr[upperStart])         
		{         
			tempArray[count++] = arr[lowerStart++];         
		}         
		else         
		{
			tempArray[count++] = arr[upperStart++];         
		}
	}
	while (lowerStart <= lowerStop)
	{         
		tempArray[count++] = arr[lowerStart++];
	}
	while (upperStart <= upperStop)
	{         
		tempArray[count++] = arr[upperStart++];
	}
	for (int i = lowerIndex; i <= upperIndex; i++)
	{         
		arr[i] = tempArray[i];
	} 
}

int main() 
{
    vector<int> data = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	InsertionSort *bs = new InsertionSort(data);
	bs-> sort();
	for (int i = 0; i < data.size(); i++)
	    cout << data[i] << " ";
	return 0; 
}
