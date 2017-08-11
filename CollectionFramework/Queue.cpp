#include<iostream>
#include<conio.h>
#include<queue> 

using namespace std;

void display(queue<int> &que)
{
	cout<<"\nElements of queue are: ";
	
	/* FOR LOOP doesn't access all elements of queue
	   for (unsigned int i = 0; i < que.size(); i++)
	   {
	  	 	cout << que.front() << " ";
	   		que.pop();
	   }
	*/
	while (!que.empty()) //empty() returns 0 if queue is not empty, otherwise it returns 1.
	{
		cout << que.front() << " ";
	  	que.pop();
	}
	cout<<"\n";
}

int main() 
{
	int val, sum = 0, x = 0;
	
	queue<int> eva;
	for(int i=1;i<10;i++)
	{
		eva.push(i*11);
	}

	queue<int> que;
	vector<int> arr = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	for (auto i : arr)
		que.push(i);

	cout<<"1. Display all elements.\n";
	cout<<"2. Display size of queue.\n";
	cout<<"3. Sum of all elements in queue.\n";
	cout<<"4. Display the element at the front of queue.\n";
	cout<<"5. Insert element.\n";
	cout<<"6. Emplace.\n";// Adds a new element at the top of the stack, above its current top element
	cout<<"7. Remove front element.\n";
	cout<<"8. Swap contents.\n";

	int ch;
	cout<<"\nEnter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			display(que);
			break;
		case 2:
			cout <<"\nSize of queue: " << que.size();
			break;
		case 3:
			while (!que.empty())
			{
		   		sum += que.front();
		   		que.pop();
			}
	  		cout << "\nSum of all elements: " << sum << '\n';
			break;
		case 4:
			cout<<"\nElement at the front of queue: "<<que.front();
			break;
		case 5:
			cout<<"\nEnter the value to be inserted: ";
			cin>>val; 
			que.push(val);
			display(que);		
			break;
		case 6:
			cout<<"\nEnter the value to be emplaced(add to front): ";
			cin>>val;
			que.emplace(val);
			display(que);
			break;
		case 7:
			que.pop();
			cout<<"\nAfter Removing front element.";
			display(que);
			break;
		case 8:
			que.swap(eva);
			display(que);
			break;
		default:cout<<"\nEnter correct choice: ";
	}
	
	return 0;
}
