#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;
// Array of n-1 elements, in range of 1 to n.
// No duplicates in array. One integer is missing.
// Find the missing integer.
	
// Brute force
int findMissingNumber1(vector<int> &data) 
{
	int found;
	int size = data.size();
	for (int i = 1; i <= size; i++)
	{
		found = 0;
		for (int j = 0; j < size; j++)
		{
			if (data[j] == i)
			{        
                found = 1;        
				break;
			}
		}
		if (found == 0)
		{
			return i;
		}
	}
	return -1;
}

// using XOR sum
int findMissingNumber2(vector<int> &data, int range) 
{
	int size = data.size(); 
    int xorSum = 0; 
    // get the XOR of all the numbers from 1 to range 
	for (int i = 1; i <= range; i++) 
	{ 
        xorSum ^= i; 
        //cout << endl << xorSum;
    } 
	// cout<<endl;
	
    // loop through the array and get the XOR of elements 
	for (int i = 0; i < size; i++) 
	{ 
        xorSum ^= data[i];
        //cout << endl << xorSum;
	}
	return xorSum; 
}

int main()
{
	vector<int> arr = { 9, 6, 4, 1, 3, 2, 8, 7 };

	int major = findMissingNumber2(arr,9);
	if (major != -1)
		cout<<"\nMissing number is: "<<major;
	else
		cout<<"\nNo missing number.";
	
    return 0;
}