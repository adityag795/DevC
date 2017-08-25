#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<exception>
using namespace std;

class Stack 
{ 
	private:
		struct Node
		{
			int value = 0;
			Node* next;
			Node(int,Node*);
		};
		Node* head = nullptr;
		int stack_size; 
    public:// Stack class API-methods .
        Stack();
        Stack(int);
        virtual int size();
        virtual bool isEmpty();
        virtual int peek();
        virtual void push(int);
        virtual int pop();
        virtual void print(); 
};

Stack:: Stack() 
{ 
    stack_size = 10;
}

Stack:: Stack(int MaxCapacity) 
{
	stack_size = MaxCapacity; 
}


Stack:: Node:: Node(int v, Node* n) 
{
	value = v;
	next = n; 
} 

int Stack:: size() 
{
	return stack_size; 
} 

bool Stack:: isEmpty() 
{
	return stack_size == 0; 
} 

int Stack:: peek() 
{
	if (isEmpty())
    {   
        return -1;
    }
	return head-> value; 
} 

void Stack:: push(int value) 
{
	head = new Node(value, head);
	stack_size++; 
} 

int Stack:: pop()
{
	if (isEmpty())
	{   
        return -1;
    }
	int value = head-> value;
	Node* delMe = head;
	head = head-> next;
	delete delMe;
	stack_size--;
	return value; 
} 

void Stack:: print() 
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp-> value << " ";
		temp = temp-> next;
	} 
} 

int main()
{
	int cal;
    cout<<"\nEnter an initial size of your stack: ";
    cin>>cal;
    Stack s(cal);
	
    int ch, opt = 0;
    cout<<"\n1. Push.";
	cout<<"\n2. Pop.";
	cout<<"\n3. Size.";
	cout<<"\n4. Print all.";
    cout<<"\n5. Element at top.";
    cout<<"\n6. Exit.";
    
    do
	{
		cout << "\nEnter your choice: ";	
		cin >> ch;
		int val;
		bool res;
		switch (ch)
		{
			case 1:
                cout<<"\nEnter the value you want to push: ";
                cin>>val;
                s.push(val);
				break;
			case 2:
                val = s.pop();
                if(val != -1)
                    cout<<"\nValue popped is "<<val;
                else
                    cout<<"\nStack is empty.";
				break;
			case 3:
                val = s.size();
                cout<<"\nSize of stack is "<<val;
				break;
			case 4:
                cout<<"\nValues stored in stack are ";
                s.print();
				break;
			case 5:
                if (s.peek() != -1)
                    cout<<"\nElement at the top is "<<s.peek();
                else
                    cout<<"\nStack is empty.";
                break;
			case 6:
				opt=6;
				break;
			default:cout<<"\nPlease enter the correct choice: ";
		}
	}while(opt != 6);
	
	return 0;	
}