#include<iostream>
#include<conio.h>
#include<stack> 
#include<vector>

using namespace std;

void display(stack<int> &stk)
{
	cout<<"\nElements in stack: ";
	while (!stk.empty())
  	{
	    cout << stk.top() << '\t';
    	stk.pop();
  	}
	cout << endl;
}

int main() 
{
	stack<int> eva;
	for (int i=90; i<100; ++i) 
		eva.push(i);

	stack<int> stk;
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (auto i : arr)
	{
		stk.push(i);
	}
	
	int val;

	cout<<"1. Display all elements.\n";
	cout<<"2. Display size of stack.\n";
	cout<<"3. Display element at the top.\n";
	cout<<"4. Insert element.\n";
	cout<<"5. Emplace.\n";// Adds a new element at the top of the stack, above its current top element
	cout<<"6. Remove top element.\n";
	cout<<"7. Swap contents.\n";

	int ch;
	cout<<"\nEnter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			display(stk);
			break;
		case 2:
			cout <<"\nSize of stack: " << stk.size();
			break;
		case 3:
			cout<<"\nElement at the top: "<<stk.top();
			break;
		case 4:
		 	cout<<"\nEnter the value to be inserted: ";
			cin>>val; 
			stk.push(val);
			display(stk);		
			break;	
		case 5:
			cout<<"\nEnter the value to be emplaced(add to top): ";
			cin>>val;
			stk.emplace(val);
			display(stk);
			break;
		case 6:
			stk.pop();
			cout<<"\nAfter Removing top element.";
			display(stk);
			break;
		case 7:
			stk.swap(eva);
			display(stk);
			break;
		default:cout<<"Please enter correct choice(1-7): ";
	}

	return 0; 
}