#include<iostream>
#include<vector>
using namespace std;

void printVector(std::vector<int> &data)
{
	int count = data.size();
	cout<<"Values stored are: ";
	for(int i = 0;i<count;i++)
	{
		cout<<" "<<data[i];
	}
}

void reverseArray(std:: vector<int> &a, int start, int end) 
{ 
	for (int i = start, j = end; i < j; i++, j--) 
	{ 
		int temp = a[i]; 
		a[i] = a[j]; 
		a[j] = temp; 
	} 
}

void rotateArray(std::vector<int> &arr, int k) 
{ 
	int n = arr.size(); 
	reverseArray(arr, 0, k - 1); 
	reverseArray(arr, k, n - 1); 
	reverseArray(arr, 0, n - 1); 
} 

int main()
{
	vector<int> vec;
	vector<int>::iterator it;

	cout<<"Enter the size of the Vector Array: ";
	int size,val;
	cin>>size;

	cout<<"\nNow, enter the values: ";
	for(int i = 0; i<size; i++)
	{
		it = vec.begin();
		cin>>val;
		it = vec.insert( it, val);
	}

	printVector(vec);

	int k;
	cout<<"\nBy how many positions, do you want to rotate the array?";
	cin>>k;
	rotateArray(vec,k);

	cout<<"\nAfter Rotation by "<<k<<" positions \n";
	printVector(vec);

	return 0;
}