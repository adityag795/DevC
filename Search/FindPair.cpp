#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

// Brute-Force method
bool FindPair(vector<int> &data, int value) 
{
	int size = data.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (( data[i] + data[j]) == value)
			{        
				cout << "The pair is : " << data[i] << ", " << data[j] << endl;
				return true;
		 	}
		}
	}
	return false; 
}

// Using Sorting
bool FindPair2(vector<int> &data, int value) 
{
	int size = data.size();
	int first = 0, second = size - 1;
	int curr;
	sort( data.begin(), data.end()); // Sort( data, size);
	while (first < second)
	{
		curr = data[first] + data[second];
		if (curr == value)
		{
			cout << "The pair is " << data[first] << ", " << data[second] <<  endl;
			return true;
		}
		else if (curr < value)
			first++;
		else
			second--;
	}
	return false; 
}

// using Hash Table
bool FindPair3(vector<int> &data, int value) 
{
	unordered_set<int> hs;
	int i;
    int size = data.size();
    int pair = 0;
	for (i = 0; i < size; i++)
	{
		if (find( hs.begin(), hs.end(), value - data[i]) != hs.end())
		{
			cout << "\nThe pair is : " << data[i] << " , " << (value - data[i]) << endl;
            pair++;
            //return true;
		}
		hs.insert(data[i]);
    }
    if (pair == 0) // To find multiple pairs.
        return false; 
    else
        return true;
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
	vector<int> arr = { 9, 8, 2, 5, 9, 6, 12, 21 };
    display(arr);
    int val;
    cout << "\nEnter the Sumvalue: ";
    cin >> val;
    bool pair = FindPair3(arr, val);
    
    if (!pair)
		cout<<"\nNo elements form the sum.";	
	
    return 0;
}