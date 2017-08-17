#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

// Brute Force 
void minabsSumPair(vector<int> &data) 
{ 
	int minSum, sum, minFirst, minSecond; 
	int size = data.size(); 
	// Array should have at least two elements 
	if (size < 2) 
	{ 
		throw exception(" InvalidInput"); 
	}
	// Initialization of values 
	minFirst = 0; 
	minSecond = 1; 
	minSum = abs( data[0] + data[1]); 
	for (int l = 0; l < size - 1; l++) 
	{ 
		for (int r = l + 1; r < size; r++) 
		{
			sum = abs( data[l] + data[r]);
			if (sum < minSum)
			{
				minSum = sum;
				minFirst = l;
				minSecond = r;
			} 
		} 
	} 
	cout << "\nThe two elements with minimum sum are : " << data[minFirst] << " , " << data[minSecond] << endl; 
}

// Using Sorting
void minabsSumPair2(vector<int> &data) 
{
	int minSum, sum, minFirst, minSecond;
	int size = data.size();
	if (size < 2) // Array should have at least two elements
	{
		throw exception("InvalidInput");
	}
	sort(data.begin(), data.end()); // Sort( data, size);
	
	// Initialization of values
	minFirst = 0;
	minSecond = size - 1;
	minSum = abs( data[minFirst] + data[minSecond]);
	for (int l = 0, r = size - 1; l < r;)
	{
		sum = (data[l] + data[r]);
		if (abs(sum) < minSum)
		{
			minSum = abs(sum);
			minFirst = l;
			minSecond = r;
		}
		if (sum < 0)
			l++;
		else if (sum > 0)
			r--;
		else
			break;
	}
	cout << "\nThe two elements with minimum sum are : " << data[minFirst] << " , " << data[minSecond] << endl; 
}

// Display elements of vector
void display(vector<int> &vec)
{
    int count = vec.size();  // Return size
    cout<<"\nValues stored are: ";
    for(int i = 0; i < count; i++)
    {
        cout<<" "<<vec[i];
    } 
}

int main()
{
	vector<int> arr = { 9, 8, 2, 5, -9, 6, 12, 21 };
    display(arr);
    
    minabsSumPair2(arr);
        	
    return 0;
}