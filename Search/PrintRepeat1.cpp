// Using Sorting
#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

void printRepeating1(vector<int> &data) 
{
	int size = data.size();
	sort(data.begin(), data.end()); // Sort( data, size);It takes O(nlogn) time.
	cout << "\nRepeating elements are : ";
	for (int i = 1; i < size; i++)
	{
		if (data[i] == data[i - 1])
			cout << " " << data[i];
	} 
}

int main()
{
	vector<int> arr = {12,34,56,84,29,98,75,5,12};
	
	printRepeating1(arr);

	return 0;
}