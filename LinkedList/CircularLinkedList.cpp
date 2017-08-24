#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<exception>
using namespace std;

class CircularLinkedList 
{ 
	private:
		struct Node
		{
			int value;
			Node* next;
			Node(int,Node*);
			Node(int);
		};
	private:
		Node* tail;
		int list_size; 
	public:
		CircularLinkedList();
		virtual int size();
		virtual bool isEmpty();
		virtual int peek();
		virtual void addHead(int);
		virtual int removeHead();// Other methods. 
		virtual void addTail(int);
		virtual bool isPresent(int);
		virtual void print();
		virtual void freeList();
		virtual bool removeNode(int);

		virtual CircularLinkedList* copyListReversed();
		virtual CircularLinkedList* copyList();
};

 CircularLinkedList:: Node:: Node( int v, Node *n) 
 {
 	value = v;
	next = n; 
} 

CircularLinkedList:: Node:: Node( int v) 
{
	value = v;
	next = nullptr; 
} 

CircularLinkedList:: CircularLinkedList() 
{
	list_size = 0; 
}

int CircularLinkedList:: size() 
{
	return list_size; 
} 

bool CircularLinkedList:: isEmpty() 
{
return list_size == 0; 
} 

int CircularLinkedList:: peek() 
{
	if (isEmpty())
		return -1;
	return tail-> next-> value; 
}

void CircularLinkedList:: addHead( int value) 
{
	Node* temp = new Node( value, nullptr);
	if (isEmpty())
	{
		tail = temp;
		temp-> next = temp;
	}
	else
	{
		temp-> next = tail-> next;
		tail-> next = temp;
	}
	list_size++; 
}

void CircularLinkedList:: addTail( int value) 
{
	Node* temp = new Node( value, nullptr);
	if (isEmpty())
	{
		tail = temp;
		temp-> next = temp;
	}
	else
	{
		temp-> next = tail-> next;
		tail-> next = temp;
		tail = temp;
	}
	list_size++; 
}

int CircularLinkedList:: removeHead() 
{
	if (isEmpty())
	{
		return -1;
	}
	int value = tail-> next-> value;
	Node* delMe = tail-> next;
	if (tail == tail-> next)
	{
		tail = nullptr;
	}
	else
	{
		tail-> next = tail-> next-> next;
	}
	delete delMe;
	list_size--;
	return value; 
}

bool CircularLinkedList:: isPresent( int data) 
{
	Node* temp = tail;
	for (int i = 0; i < list_size; i++)
	{
		if (temp-> value == data)
		return true;
		temp = temp-> next;
	}
	return false; 
}

void CircularLinkedList:: print()
{
	if (isEmpty())
		return;
	Node* temp = tail-> next;
	while (temp != tail)
	{
		std:: cout << temp-> value << " ";
		temp = temp-> next;
	}
	std:: cout << temp-> value; 
}

void CircularLinkedList:: freeList()
{
	if (tail == nullptr)
		return;
	Node* curr = tail-> next;
	Node* next;
	while (curr != tail)
	{
		next = curr-> next;
		delete curr;
		curr = next;
	}
	delete tail;
	tail = nullptr;
	list_size = 0; 
}

bool CircularLinkedList:: removeNode( int key)
{
	if (isEmpty())
		return false;

	Node* prev = tail;
	Node* curr = tail-> next;
	Node* head = tail-> next;

	if (curr-> value == key) // head and single node case.
	{
		if (curr == curr-> next) // single node case.
		{
			tail = nullptr;
		}
		else // Node to be deleted is head.
		{
			tail-> next = tail-> next-> next;
		}
		delete curr;
		return true;
	}
	// Now since head and tail node do not contain the value
	prev = curr;// Move prev one node ahead
	curr = curr-> next;// Move curr one node ahead
	while (curr != head)
	{
		if (curr-> value == key)
		{
			if (curr == tail)// If tail node has the del Value
			{        
				tail = prev;
			}
			prev-> next = curr-> next;
			delete curr;
			return true;
		}
		prev = curr;
		curr = curr-> next;
	}
	return false;
}

CircularLinkedList* CircularLinkedList:: copyListReversed() 
{
	CircularLinkedList* cl = new CircularLinkedList();
	Node* curr = tail-> next;
	Node* head = curr;
	if (curr != nullptr)
	{
		cl-> addHead( curr-> value);
		curr = curr-> next;
	}
	while (curr != head)
	{
		cl-> addHead( curr-> value);
		curr = curr-> next;
	}
	return cl; 
}

CircularLinkedList* CircularLinkedList:: copyList() 
{
	CircularLinkedList* cl = new CircularLinkedList();
	Node* curr = tail-> next;
	Node* head = curr;
	if (curr != nullptr)
	{
		cl-> addTail( curr-> value);
		curr = curr-> next;
	}
	while (curr != head)
	{
		cl-> addTail( curr-> value);
		curr = curr-> next;
	}
	return cl; 
}

int main() 
{
	int ch, opt = 0;
	cout<<"\n1. Check size of list.";
	cout<<"\n2. Peek value at top/head.";
	cout<<"\n3. Add head.";
	cout<<"\n4. Remove head.";
	cout<<"\n5. Add node to the end/tail.";
	cout<<"\n6. Check if value is present or not.";
	cout<<"\n7. Print all the values.";
	cout<<"\n8. Delete list/free list.";
    cout<<"\n9. Remove node with some value.";
    cout<<"\n10. Copy list reversed.";
	cout<<"\n11. Copy list.";
	cout<<"\n12. Exit.";
    
	CircularLinkedList* ll = new CircularLinkedList();
	CircularLinkedList* l2;
	int op;
	do
	{
		cout<<"\nEnter your choice: ";	
		cin>>ch;
		int val;
		bool res;
		switch (ch)
		{
            case 1:
				op = ll->size();
				cout<<"\nThe size of Circular Linked List is "<<op;
                break;
            case 2:
				op = ll->peek();
				if (op != -1)
					cout<<"\nNode at the top/head contains: "<<op;
				else	
					cout<<"\nLinked List is empty.";
                break;
			case 3:
				cout << "\nEnter the value you want to insert ";
				cin >> val;
                ll->addHead(val);
                break;
            case 4:
				op = ll->removeHead();
				if (op != -1)
					cout<<"\nValue removed from top is "<<op;
				else	
					cout<<"\nLinked List is empty.";
				break;
            case 5:
				cout<<"\nEnter the value you want to insert at tail:";
				cin>>val;
				ll->addTail(val);
                break;
            case 6:
				cout<<"\nEnter the value to check if it is present or not:";
				cin>>val;
				res = ll->isPresent(val);
				if (res)
					cout<<"\nValue is present.";
				else	
					cout<<"\nValue is not present.";
                break;
            case 7:
				cout<<"Values stored in Circular Linked List are: ";
				ll->print();
                break;
            case 8:
				ll->freeList();
				cout<<"\nList deleted.";
                break;
            case 9:
				cout<<"\nEnter the value to check if it is present or not:";
				cin>>val;
				res = ll->removeNode(val);
				if (res)
					cout<<"\nNode with Value deleted.";
				else	
					cout<<"\nNode with Value not found.";
                break;
            case 10:
				l2 = ll->copyListReversed();
				cout<<"Values stored in copied Circular Linked List are: ";
				l2->print();
                break;
            case 11:
				l2 = ll->copyList();
				cout<<"Values stored in copied Circular Linked List are: ";
				l2->print();
                break;
            case 12:
                opt = 12;
                break;
            default:cout<<"\nPlease Enter correct choice: ";
        }
    }while(opt != 12);

	return 0; 
}