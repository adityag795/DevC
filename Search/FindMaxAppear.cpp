#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

// Using Counting
int getMax3(vector<int> &data, int range) 
{
	int max = data[0], maxCount = 1;
	int size = data.size();
	vector<int> count(range);
	for (int i = 0; i < size; i++)
	{
		count[data[i]]++;
		if (count[data[i]] > maxCount)
		{
			maxCount = count[data[i]];
			max = data[i];
		}
	}
	return max; 
}

// Using Sorting
int getMax2(vector<int> &data) 
{
	int size = data.size(); 
	int max = data[0], maxCount = 1; 
	int curr = data[0], currCount = 1; 
	sort(data.begin(), data.end()); 
	
	for (int i = 0; i < size; i++) 
	{ 
		if (data[i] == data[i - 1]) 
		{	
			currCount++;
		}
		else 
		{ 
			currCount = 1; 
			curr = data[i]; 
		} 
		if (currCount > maxCount) 
		{ 
			maxCount = currCount; 
			max = curr; 
		} 
	} 
	return max;
}

int main()
{
	vector<int> arr = { 90, 82, 82, 55, 90, 55, 55, 99, 55 };

	cout<<"\nMaximum appearing element (using Sorting) is "<<getMax2(arr);

	cout<<"\nMaximum appearing element (using Counting) is "<<getMax3(arr,100);
	
    return 0;
}