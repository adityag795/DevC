#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<exception>
using namespace std;

class Stack 
{ 
	private:
		static const int MIN_CAPACITY = 10;
		int* data;
		int stack_top = -1;
		int capacity; 
	public:
		Stack();
		Stack(int);
		~Stack();
		virtual int size();
		virtual bool isEmpty();
		virtual int top();
		virtual void push(int);
		virtual int pop();
		virtual void print(); 
};

Stack:: Stack() : Stack( MIN_CAPACITY) { } 

Stack:: Stack( int MaxCapacity) 
{
	data = new int[ MaxCapacity];
	capacity = MaxCapacity; 
}

Stack:: ~Stack() 
{
	delete[] data;
}

bool Stack:: isEmpty() 
{
	return (stack_top == -1); 
}

int Stack:: size() 
{
	return (stack_top + 1); 
}

void Stack:: print() 
{
	for (int i = stack_top; i > -1; i--)
	{         
		cout << " " << data[i];
	} 
}

void Stack:: push( int value) 
{
	if (size() == capacity)
	{         
        cout<<"\n Stack Overflow.";
        return;
	}
	stack_top++;
	data[stack_top] = value; 
}

int Stack:: pop() 
{
	if (isEmpty())
	{
        return -1;
	}
	int topVal = data[ stack_top];
	stack_top--;
	return topVal; 
}

int Stack:: top() 
{
	if (isEmpty())         
	{   
        return -1;
    }
	return data[ stack_top]; 
}

int main() 
{
    int cal;
    cout<<"\nEnter the size of your stack: ";
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
                if (s.top() != -1)
                    cout<<"\nElement at the top is "<<s.top();
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