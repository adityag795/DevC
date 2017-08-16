// Using Sorting
#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

// When we know that, the elements in the array are in range 1 to n-1.
// Find the duplicate elements in array.

// This won't work with 0. Handle the 0 case by incrementing with 1.
void printRepeating(vector<int> arr)
{
    int i;
  	printf("The repeating elements are: \n");
  	for (i = 0; i < arr.size(); i++)  // This gives O(n) time complexity and O(1) constant space.
  	{
    	if (arr[abs(arr[i])] >= 0)
	  	    arr[abs(arr[i])] = -arr[abs(arr[i])];
      else
          printf(" %d ", abs(arr[i]));
    }
}

/*
void printRepeating3(vector<int> &data) 
{
	int size = data.size();
	vector<int> count(size);
	for (int i = 0; i < size; i++)
	{
		count[i] = 0;
	}
	cout << "Repeating elements are : ";
	for (int i = 0; i < size; i++)
	{
		if (count[data[i]] == 1)
			cout << " " << data[i];
		else
			count[data[i]]++;
	} 
}
*/
	
int main()
{
	vector<int> arr = {1,2,3,1,3,6,6};
	
	printRepeating(arr);

	return 0;
}
