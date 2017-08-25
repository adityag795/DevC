#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<exception>
using namespace std;

class DoublyLinkedList
{ 
	private:
		struct Node
		{
			int value;
			Node* next;
			Node* prev;
			Node(int, Node* , Node*);
			Node(int);
		};
		Node* head;
		Node* tail;
		int list_size; 
	public:
		DoublyLinkedList();
		virtual int size();
        virtual bool isEmpty();
        virtual bool isPresent(int);
        virtual bool removeNode(int);
        virtual void removeDuplicate();
		virtual int peek();
        virtual void addHead(int);
        virtual void addTail(int);
        virtual int removeHead();
        virtual void freeList();
        virtual void print();
        virtual void reverseList();
        virtual void sortedInsert(int);
        virtual void copyListReversed( DoublyLinkedList& );
        virtual void copyList( DoublyLinkedList& );
};

DoublyLinkedList:: Node:: Node(int v, Node *nxt, Node *prv) 
{
	value = v;
	next = nxt;
	prev = prv; 
}

DoublyLinkedList:: Node:: Node(int v) 
{
	value = v;
	next = nullptr;
	prev = nullptr; 
}

// Defining Constructor
DoublyLinkedList:: DoublyLinkedList() 
{
	list_size = 0;
}

// Return the size of the list.
int DoublyLinkedList:: size() 
{
	return list_size; 
}

// Return if the list is empty.
bool DoublyLinkedList:: isEmpty() 
{
	return list_size == 0; 
}

// Return top element / Head element.
int DoublyLinkedList:: peek() 
{
	if (isEmpty())
		cout << "\nLinked List is empty.";
	return head-> value; 
}

// Insert at Head.
void DoublyLinkedList:: addHead(int value) 
{
	Node *newNode = new Node(value, nullptr, nullptr);
	// Zero element check
	if (list_size == 0)
	{
		tail = head = newNode;
	}
	else
	{
		head-> prev = newNode;
		newNode-> next = head;
		head = newNode;
	}
	list_size++; 
}

// Insert at Tail.
void DoublyLinkedList:: addTail(int value)
{
	Node *newNode = new Node( value, nullptr, nullptr);
	// Zero element check
	if (list_size == 0)
	{
		head = tail = newNode;
	}
	else
	{
		newNode-> prev = tail;
		tail-> next = newNode;
		tail = newNode;
	}
	list_size++;
}

// Remove Head of Doubly Linked List.
int DoublyLinkedList:: removeHead() 
{
	if (isEmpty())
	{		
		cout<<"\nThe list is empty.";
		return -1;
	}
	Node* deleteMe;
	int value = head-> value;
	deleteMe = head;
	head = head-> next;
	// If head element was the only element in the linked list
	if (head == nullptr)
	{
		tail = nullptr;
	}
	else
	{
		head-> prev = nullptr;
	}
	delete deleteMe;
	list_size--;
	return value; 
}

// Delete a node in Doubly Linked List.
bool DoublyLinkedList:: removeNode(int key) 
{
	Node* curr = head;
	Node* deleteMe;
	if (curr == nullptr) // empty list
		return false;
	if (curr-> value == key) // head is the node with value key.
	{
		deleteMe = curr;
		curr = curr-> next;
		delete deleteMe;
		list_size--;
		if (curr != nullptr)
		{
			head = curr;
			head-> prev = nullptr;
		}
		else
		tail = nullptr; // only one element in list.
		return true;
	}
	while (curr-> next != nullptr)
	{
		if (curr-> next-> value == key)
		{
			deleteMe = curr-> next;
			curr-> next = curr-> next-> next;
			if (curr-> next == nullptr) // last element case.        
				tail = curr;
			else        
				curr-> next-> prev = curr;
			delete deleteMe;
			list_size--;
			return true;
		}
		curr = curr-> next;
	}
	return false; 
}

// Search List.
bool DoublyLinkedList:: isPresent( int key) 
{
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp-> value == key)
			return true;
		temp = temp-> next;
	}
	return false;
}

// Free list.
void DoublyLinkedList:: freeList() 
{
	Node* curr = head;
	Node* next;
	while (curr != nullptr)
	{
		next = curr-> next;
		delete curr;
		curr = next;
	}
	tail = head = nullptr;
	list_size = 0;
}

// Print list.
void DoublyLinkedList:: print() 
{
	Node *temp = head;
	while (temp != nullptr)
	{
		cout << temp-> value << string(" ");
		temp = temp-> next;
	} 
}

// Reverse a doubly linked List iteratively.
void DoublyLinkedList:: reverseList() 
{
	Node* curr = head;
	Node* tempNode;
	while (curr != nullptr)
	{
		tempNode = curr-> next;
		curr-> next = curr-> prev;
		curr-> prev = tempNode;
		if (curr-> prev == nullptr)
		{
			tail = head;
			head = curr;
			return;
		}
		curr = curr-> prev;
	}
	return; 
}

// Copy List Reversed.
void DoublyLinkedList:: copyListReversed( DoublyLinkedList& dll) 
{
	Node* curr = head;
	while (curr != nullptr)
	{
		dll.addHead( curr-> value);
		curr = curr-> next;
	}
}

// Copy List.
void DoublyLinkedList:: copyList( DoublyLinkedList& dll) 
{
	Node* curr = head;
	while (curr != nullptr)
	{
		dll.addTail( curr-> value);
		curr = curr-> next;
	} 
}

// Sorted Insert.
void DoublyLinkedList:: sortedInsert( int value) 
{
	Node* temp = new Node(value);
	Node* curr = head;
	if (curr == nullptr) // first element
	{
		head = temp;
		tail = temp;
	}
	if (head-> value <= value) // at the begining
	{
		temp-> next = head;
		head-> prev = temp;
		head = temp;
	}
	while (curr-> next != nullptr && curr-> next-> value > value)      // treversal
	{
		curr = curr-> next;
	}
	if (curr-> next == nullptr)   // at the end
	{
		tail = temp;
		temp-> prev = curr;
		curr-> next = temp;
	}
	else	// all other
	{
		temp-> next = curr-> next;
		temp-> prev = curr;
		curr-> next = temp;
		temp-> next-> prev = temp;
	} 
}

// Remove Duplicate.
void DoublyLinkedList:: removeDuplicate() 
{
	Node *curr = head;
	Node *deleteMe;
	while (curr != nullptr)
	{
		if (( curr-> next != nullptr) && curr-> value == curr-> next-> value)
		{		        
			deleteMe = curr-> next;
			curr-> next = deleteMe-> next;
			curr-> next-> prev = curr;
			if (deleteMe == tail)
			{        
				tail = curr;
			}
			delete deleteMe;
		}
		else
		{
			curr = curr-> next;
		}
	} 
}

int main()
{
    int ch, opt = 0;
	cout<<"\n1. Insert at the begining / Head of Doubly Linked List.";
	cout<<"\n2. Insert at the end / Tail of Doubly Linked List.";
	cout<<"\n3. Remove head of Doubly Linked List.";
	cout<<"\n4. Delete a node in Doubly Linked List.";
	cout<<"\n5. Search an element in Linked List.";
	cout<<"\n6. Free List.";
	cout<<"\n7. Print List.";
    cout<<"\n8. Reverse a Doubly Linked List.";
    cout<<"\n9. Copy List.";
    cout<<"\n10. Copy List reveresed.";
    cout<<"\n11. Sorted Insert.";
    cout<<"\n12. Remove Duplicate.";
    cout<<"\n13. Exit.";
    
    DoublyLinkedList* ll = new DoublyLinkedList();
    DoublyLinkedList l2;
    do
	{
		cout<<"\nEnter your choice: ";	
		cin>>ch;
		int val;
		bool res;
		switch (ch)
		{
            case 1:
                cout << "\nEnter the element you want to insert in head: ";
                cin >> val;
                ll->addHead(val);
                break;
            case 2:
                cout << "\nEnter the element you want to insert in tail: ";
                cin >> val;
                ll->addTail(val);
                break;
            case 3:
                ll->removeHead();
                cout << "\nHead of the Doubly Linked List removed.";
                break;
            case 4:
                cout << "\nEnter the value stored in node you want to delete: ";
                cin >> val;
                res = ll->removeNode(val);
                if(res)
                    cout<<"\nNode deleted successfully.";
                else	
                    cout<<"\nNo Node contains the value "<< val<<".";
                break;
            case 5:
                cout << "\nEnter the element you want to search: ";
                cin >> val;
                if(ll->isPresent(val))
                    cout<<"\nElement is present in the list.";
                else	
                    cout<<"\nElement is not present in the list.";
                break;
            case 6:
                ll->freeList();
                cout<<"\nLinked List deleted successfully.";
                break;
            case 7:
                cout << "\nElements in the linked list are: ";
                ll->print();
                break;
            case 8:
                ll->reverseList();
                cout<<"\nAfter reversing list, elements in the list are: ";
                ll->print();
                break;
            case 9:
                ll->copyList(l2);
                cout<<"\nCopied List is: ";
                l2.print();
                break;
            case 10:
                ll->copyListReversed(l2);
                cout<<"\nCopied Reverse List is: ";
                l2.print();
                break;
            case 11:
                cout << "\nEnter the element you want to sorted insert: ";
                cin >> val;
                ll->sortedInsert(val);
                break;
            case 12:
                ll -> removeDuplicate();
                cout<<"\nAfter removing duplicates, elements in list are: ";
                ll->print();
                break;
            case 13:
                opt = 13;
                break;
            default:cout<<"\nPlease Enter correct choice: ";
        }
    }while(opt != 13);

    return 0;
}