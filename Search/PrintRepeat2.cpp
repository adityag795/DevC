// Using Hash Table
#include<iostream>
#include<conio.h>
#include<vector>
#include<unordered_set>

using namespace std;

// Using Hash-Tables
void printRepeating2(vector<int> &data) 
{
	unordered_set<int> hs;
	int size = data.size();
	cout << "Repeating elements are : " ;
	for (int i = 0; i < size; i++) // Time complecity is O(n)
	{
		if (find( hs.begin(), hs.end(), data[i]) != hs.end())
			cout << " " << data[i];
		else
			hs.insert(data[i]); // Space Complexity is O(n)
	}
}

int main()
{
	vector<int> arr = {12,34,56,84,29,98,75,5,12};
	
	printRepeating2(arr);

	return 0;
}