#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

// using sorting
int getMajority2(vector<int> &data) 
{ 
	int size = data.size(); 
	int majIndex = size / 2, count; 
	int candidate; 

	sort(data.begin(), data.end()); // Sort( data, size); 
	candidate = data[majIndex]; 
	count = 0; 

	for (int i = 0; i < size; i++) 
	{ 
		if (data[i] == candidate)
			count++; 
	}
	if (count > size/2)
		return data[majIndex];
	else
		return -1; 
}

// using cancelation approach(Moore's Voting Algorithm)
int getMajority3(vector<int> &data) 
{
	int majIndex = 0, count = 1;
	int candidate;
	int size = data.size();
	for (int i = 1; i < size; i++)
	{
		if (data[majIndex] == data[i])
			count++;
		else
			count--;
		
		if (count == 0)
		{
			majIndex = i;
			count = 1;
		}
	}
	candidate = data[majIndex];
	count = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == candidate)
		{
			count++;
		}
	}
	if (count > size / 2)
		return data[majIndex];
	else
		return -1; 
}

int main()
{
	vector<int> arr = { 90, 82, 82, 55, 90, 55, 55, 99, 55, 55, 55 };

	int major = getMajority3(arr);
	if (major != -1)
		cout<<"\nMajority element is: "<<major;
	else
		cout<<"\nMajority element does not exist.";
	
    return 0;
}
