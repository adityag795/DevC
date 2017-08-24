#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<exception>
using namespace std;

class DoublyCircularLinkedList 
{ 
	private:
		struct Node
		{
			int value;
			Node* next;
			Node* prev;
			Node(int, Node*, Node*);
			Node(int);
		};
		Node* head = nullptr;
		Node* tail = nullptr;
		int list_size = 0;
	public:
		DoublyCircularLinkedList();
		virtual int size();
		virtual bool isEmpty();
		virtual int peekHead();
		virtual void addHead(int);
        virtual int removeHead();// Other Methods. 
        virtual void addTail(int);
        virtual int removeTail();
        virtual bool isPresent(int);
        virtual void freeList();
        virtual void print();
};

DoublyCircularLinkedList:: Node:: Node(int v, Node* nxt, Node* prv)
{
	value = v;
	next = nxt;
	prev = prv; 
} 

DoublyCircularLinkedList:: Node:: Node(int v)
{
	value = v;
	next = this;
	prev = this;
}

DoublyCircularLinkedList:: DoublyCircularLinkedList() 
{
	list_size = 0; 
} 

int DoublyCircularLinkedList:: size() 
{
	return list_size; 
} 

bool DoublyCircularLinkedList:: isEmpty() 
{
	return list_size == 0; 
}

int DoublyCircularLinkedList:: peekHead() 
{
	if (isEmpty())
	{
        return -1;
	}
	return head-> value; 
}

bool DoublyCircularLinkedList:: isPresent( int key) 
{
	Node* temp = head;
	if (head == nullptr)
		return false;
	do
	{
		if (temp-> value == key)
		{
			return true;
		}
		temp = temp-> next;
	} while (temp != head);
	return false;
}

void DoublyCircularLinkedList:: freeList()
{
	if (head == nullptr)
		return;
	Node* curr = head-> next;
	Node* next;
	while (curr != head)
	{
		next = curr-> next;
		delete curr;
		curr = next;
	}
	delete head;
	head = nullptr;
	tail = nullptr;
	list_size = 0; 
}

void DoublyCircularLinkedList:: print() 
{
	if (isEmpty())
		return;
	Node* temp = head;
	do
	{
		cout << temp-> value << " ";
		temp = temp-> next;
	} while (temp != head); 
}

void DoublyCircularLinkedList:: addHead( int value) 
{
	Node* newNode = new Node( value);
	if (list_size == 0)
	{
		tail = head = newNode;
		newNode-> next = newNode;
		newNode-> prev = newNode;
	}
	else
	{
		newNode-> next = head;
		newNode-> prev = head-> prev;
		head-> prev = newNode;
		newNode-> prev-> next = newNode;
		head = newNode;
	}
	list_size++; 
}

void DoublyCircularLinkedList:: addTail( int value) 
{
	Node* newNode = new Node( value, nullptr, nullptr);
	if (list_size == 0)
	{
		head = tail = newNode;
		newNode-> next = newNode;
		newNode-> prev = newNode;
	}
	else
	{
		newNode-> next = tail-> next;
		newNode-> prev = tail;
		tail-> next = newNode;
		newNode-> next-> prev = newNode;
		tail = newNode;
	}
	list_size++; 
}

int DoublyCircularLinkedList:: removeHead() 
{
	if (list_size == 0)
		return -1;
	int value = head-> value;
	list_size--;
	if (list_size == 0)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return value;
	}
	Node* next = head-> next;
	next-> prev = tail;
	tail-> next = next;
	delete head;
	head = next;
	return value; 
}

int DoublyCircularLinkedList:: removeTail() 
{
	if (list_size == 0)
		return -1;
	int value = tail-> value;
	list_size--;
	if (list_size == 0)
	{
		delete tail;
		head = tail = nullptr;
		return value;
	}
	Node* prev = tail-> prev;
	prev-> next = head;
	head-> prev = prev;
	delete tail;
	tail = prev;
	return value; 
}

int main() 
{
	int ch, opt = 0;
	cout<<"\n1. Check size of list.";
	cout<<"\n2. Peek value at top/head.";
	cout<<"\n3. Add head.";
	cout<<"\n4. Remove head.";
    cout<<"\n5. Add node to the end/tail.";
    cout<<"\n6. Search an element.";
	cout<<"\n7. Remove Tail.";
    cout<<"\n8. Print the list.";
    cout<<"\n9. Exit.";
    
	DoublyCircularLinkedList* ll = new DoublyCircularLinkedList();
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
				cout<<"\nThe size of Doubly Circular Linked List is "<<op;
                break;
            case 2:
				op = ll->peekHead();
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
                val = ll->removeTail();
                if (val != -1)
                    cout<<"\nTail Removed: "<<val<<".";
                else
                    cout<<"\nList is empty.";
                break;
            case 8:
                cout<<"\nValues stored in the list are: ";
                ll->print();
                break;
            case 9:
                opt = 9;
                break;
            default:cout<<"\nPlease Enter correct choice: ";
        }
    }while(opt != 9);

	return 0; 
}