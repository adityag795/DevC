#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<exception>
using namespace std;

class LinkedList 
{
	private:
		struct Node
		{
			int value;
			Node *next;
			Node(int v,Node *n);
			Node(int v);
		};
		Node *head;
		int list_size; 
		
		public:
			virtual int size();
			virtual bool isEmpty();
		//	virtual int peek();
			virtual void addHead(int value);
			virtual void addTail(int value) ;
			virtual void print();
			virtual void sortedInsert(int value);
			virtual bool isPresent(int data);
			virtual int removeHead();
			virtual bool deleteNode(int delValue);
			virtual void deleteNodes(int delValue);
			virtual void freeList();
			virtual void reverse();
			virtual void reverseRecurse();
			virtual Node *reverseRecurseUtil( Node *currentNode, Node *nextNode);
		// Other linked list methods. 
}; 

LinkedList:: Node:: Node(int v,Node *n) 
{
	value = v;
	next = n; 
}

LinkedList:: Node:: Node(int v) 
{
	value = v;
	next = nullptr; 
}

int LinkedList:: size() 
{
	return list_size; 
}

bool LinkedList:: isEmpty() 
{
	return list_size == 0; 
}

void LinkedList:: addHead(int value) 
{
	head = new Node(value, head);
	list_size++; 
}

void LinkedList:: addTail(int value) // using head pointer, complexity of creation of list is n^2.
{
	Node *newNode = new Node(value, nullptr);
	Node *curr = head;
	// Zero element test : Checks if list is empty or not
	if (head == nullptr)
		head = newNode;
	// Move curr pointer to tail end
	while (curr-> next != nullptr)
		curr = curr-> next; // traversing through list
	curr-> next = newNode; 
	list_size++;
}

void LinkedList:: print()
{
	Node *temp = head;
	while (temp != nullptr)
	{
		cout << temp-> value << " ";
		temp = temp-> next; // traversing through list
	}
	cout << endl; 
}

void LinkedList:: sortedInsert(int value) 
{
	Node *newNode = new Node(value, nullptr);
	Node *curr = head;
	// Checks if the list is empty or not.
	if (curr == nullptr || curr-> value > value)
	{
		newNode->next = head;
		head = newNode;
		return;
	}
	// traversing through list
	while (curr-> next != nullptr && curr->next->value < value)
	{
		curr = curr-> next;
	}
	newNode-> next = curr-> next;
	curr-> next = newNode; 
}

bool LinkedList:: isPresent(int data)
{
	Node *temp = head;
	while (temp != nullptr)
	{
		if (temp-> value == data)
		{
			return true;
		}
		temp = temp-> next;
	}
	return false; 
}

int LinkedList:: removeHead()
{
	if (isEmpty())
	{
		cout<<"The list is empty.\n";
		return NULL;
	}
	Node *deleteMe = head;
	int value = head-> value;
	head = head-> next;
	list_size--;
	delete deleteMe;
	return value;
}

bool LinkedList:: deleteNode(int delValue) 
{
	Node *temp = head;
	Node *deleteMe;
	// check if list is empty.
	if (isEmpty())
	{		
		cout<<"The list is empty.\n";
		return false;
	}
	// check if node that need to be deleted is head node.
	if (delValue == head-> value)
	{
		deleteMe = head;
		head = head-> next;
		list_size--;
		delete deleteMe;
		return true;
	}
	while (temp-> next != nullptr)
	{
		if (temp-> next-> value == delValue)
		{
			deleteMe = temp-> next;
			temp-> next = temp-> next-> next;
			list_size--;
			delete deleteMe;
			return true;
		}
		temp = temp-> next;
	}
	return false; 
}

void LinkedList:: deleteNodes(int delValue)
{
	Node *currNode = head;
	Node *nextNode;
	Node *deleteMe;
	while (currNode != nullptr && currNode-> value == delValue) // first node
	{
		deleteMe = head;
		head = currNode-> next;
		currNode = head;
		delete deleteMe;
	}
	while (currNode != nullptr)
	{
		nextNode = currNode-> next;
		if (nextNode != nullptr && nextNode-> value == delValue)
		{
			deleteMe = currNode-> next;
			currNode-> next = nextNode-> next;
			delete deleteMe;
		}
		else
			currNode = nextNode;
	} 
}

void LinkedList:: freeList() 
{
	Node *curr = head;
	Node *next;
	while (curr != nullptr)
	{
		next = curr-> next;
		delete curr;
		curr = next;
	}
	head = nullptr;
	list_size = 0; 
}

void LinkedList:: reverse() 
{
	Node *curr = head;
	Node *prev = nullptr;
	Node *next = nullptr;
	while (curr != nullptr)
	{
		next = curr-> next;
		curr-> next = prev;
		prev = curr;
		curr = next;
	}
	head = prev; 
}

LinkedList:: Node *LinkedList:: reverseRecurseUtil( Node *currentNode, Node *nextNode) 
{
	Node *ret; 
	if (currentNode == nullptr) 
		return nullptr;
	if (currentNode-> next == nullptr) 
	{ 
		currentNode-> next = nextNode; 
		return currentNode; 
	} 
	ret = reverseRecurseUtil( currentNode-> next, currentNode); 
	currentNode-> next = nextNode; 
	return ret; 
} 

void LinkedList:: reverseRecurse() 
{ 
	head = reverseRecurseUtil( head, nullptr); 
}

int main()
{
	LinkedList ll = LinkedList();
	int ch, opt;
	cout<<"\n1. Insert at the begining / Head of Linked List.";
	cout<<"\n2. Insert at the end / Tail of Linked List.";
	cout<<"\n3. Insert at the Nth position of Linked List.		</>";
	cout<<"\n4. Insert in sorted order in Linked List.";
	cout<<"\n5. Print all elements of Linked List.";
	cout<<"\n6. Search an element in Linked List.";
	cout<<"\n7. Delete first element in Linked List.";
	cout<<"\n8. Delete node from Linked List given its value.";
	cout<<"\n9. Delete all the occurences of particular value in Linked List.";
	cout<<"\n10. Delete all the elements of Linked List.";
	cout<<"\n11. Reverse a Linked List.";
	cout<<"\n12. Recursively reverse a single Linked List.";
	cout<<"\n13. Remove Duplicates from Linked List.";
	cout<<"\n14. Copy the content of linked list in another linked list in reverse order.";
	cout<<"\n15. Copy the content of given linked list into another linked list.";
	cout<<"\n16. Compare two given list.";
	cout<<"\n17. Find Length.";
	cout<<"\n18. Find Nth node from beginning.";
	cout<<"\n19. Find Nth node from end.";
	cout<<"\n20. Detect a loop.";
	cout<<"\n21. Detect loop using Reverse List Approach.";
	cout<<"\n22. Detect loop type using slow pointer fast pointer approach.";
	cout<<"\n23. Remove loop in Linked List.";
	cout<<"\n24. Find intersection in Linked List.";
	cout<<"\n25. Exit";

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
				ll.addHead(val);
				break;
			case 2:
				cout << "\nEnter the element you want to insert in tail: ";
				cin >> val;
				ll.addTail(val);
				break;
			case 3:

				break;
			case 4:
				cout << "\nEnter the element you want to insert in sorted order: ";
				cin >> val;
				ll.sortedInsert(val);
				break;
			case 5:
				cout << "\nElements in the linked list are: ";
				ll.print();
				break;
			case 6:
				cout << "\nEnter the element you want to search: ";
				cin >> val;
				if(ll.isPresent(val))
					cout<<"\nElement is present in the list.";
				else	
					cout<<"\nElement is not present in the list.";
				break;
			case 7:
				val = ll.removeHead();
				if (val != NULL)
					cout << "\nElement removed from head is " << val;
				break;
			case 8:
				cout << "\nEnter the value stored in node you want to delete: ";
				cin >> val;
				res = ll.deleteNode(val);
				if(res)
					cout<<"\nNode deleted successfully.";
				else	
					cout<<"\nNo Node contains the value "<< val<<".";
				break;
			case 9:
				cout << "\nEnter the value stored in nodes you want to delete: ";
				cin >> val;
				/*res = */ll.deleteNodes(val);
				//if(res)
					cout<<"\nAll Nodes deleted successfully.";
				//else	
				//	cout<<"\nNo Node contains the value "<< val<<".";
				break;
			case 10:
				ll.freeList();
				cout<<"\nLinked List deleted successfully.";
				break;
			case 11:
				ll.reverse();
				cout << "\nAfter reversal, elements in the linked list are: ";
				ll.print();
				break;
			case 12:
				ll.reverseRecurse();
				cout << "\nAfter recursive reversal, elements in the linked list are: ";
				ll.print();
				break;
			case 17:
				cout<< "\nThe size of Linked List is "<< ll.size();
				break;
			case 25:
				opt = 25;
				break;
			default:cout<<"\nPlease enter the correct choice: ";
		}
	}while(opt != 25);
	
	return 0;
}
