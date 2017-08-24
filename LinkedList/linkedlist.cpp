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
			Node* next;
			Node(int,Node*);
			Node(int);
		};
		Node* head;
		int list_size; 
		
		public:
			virtual int size();
			virtual bool isEmpty();

			virtual int findLength();
		//	virtual int peek();
			virtual void addHead(int);
			virtual void addTail(int) ;
			virtual void print();
			virtual void sortedInsert(int);
			virtual bool isPresent(int);
			virtual int removeHead();
			virtual bool deleteNode(int);
			virtual void deleteNodes(int);
			virtual void freeList();
			virtual void reverse();
			virtual void reverseRecurse();
			virtual Node* reverseRecurseUtil(Node* , Node* );
			virtual LinkedList* CopyListReversed();
			virtual LinkedList* CopyList();
			virtual void removeDuplicate();

			virtual bool compareList(Node* , Node*);
			virtual bool compareList( LinkedList*);

			virtual int nthNodeFromBegining(int);
			virtual int nthNodeFromEnd(int);

			virtual bool loopDetect();
			virtual bool reverseListLoopDetect();

			virtual int loopTypeDetect();

			virtual void removeLoop();
			virtual Node* loopPointDetect();
			virtual Node* findIntersection(Node*, Node*);
		// Other linked list methods. 
}; 

LinkedList:: Node:: Node(int v,Node* n)
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
	Node* newNode = new Node(value);
	Node* curr = head;
	// Zero element test : Checks if list is empty or not
	if (head == nullptr)
	{	
		head = newNode;
		return;
	}
	// Move curr pointer to tail end
	while (curr-> next != nullptr)
		curr = curr-> next; // traversing through list
	curr-> next = newNode; 
	list_size++;
}

void LinkedList:: print()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp-> value << " ";
		temp = temp-> next; // traversing through list
	}
	cout << endl; 
}

void LinkedList:: sortedInsert(int value) 
{
	Node* newNode = new Node(value, nullptr);
	Node* curr = head;
	// Checks if the list is empty or head element is greater that value.
	if (curr == nullptr || curr-> value > value)
	{
		newNode->next = head; // New node is added to head since inserted val is small.
		head = newNode;
		return;
	}
	// traversing through list to stop at right position.
	while (curr-> next != nullptr && curr->next->value < value)
	{
		curr = curr-> next;
	}
	// Re-addressing the pointers.
	newNode-> next = curr-> next;
	curr-> next = newNode;
}

bool LinkedList:: isPresent(int data)
{
	Node* temp = head;
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
		cout << "The list is empty.\n";
		return NULL;
	}
	Node* delNode = head;
	int value = head-> value;
	head = head-> next;
	list_size--;
	delete delNode;
	return value;
}

bool LinkedList:: deleteNode(int delValue) 
{
	Node* temp = head;
	Node* delNode;
	// check if list is empty.
	if (isEmpty())
	{
		cout << "The list is empty.\n";
		return false;
	}
	// check if node that need to be deleted is head node.
	if (delValue == head-> value)
	{
		delNode = head;
		head = head-> next;
		list_size--;
		delete delNode;
		return true;
	}
	// Traversing the list.
	while (temp-> next != nullptr)
	{
		if (temp-> next-> value == delValue)
		{
			delNode = temp-> next;
			temp-> next = temp-> next-> next;
			list_size--;
			delete delNode;
			return true;
		}
		temp = temp-> next;
	}
	return false; 
}

void LinkedList:: deleteNodes(int delValue)
{
	// check if list is empty.
	if (isEmpty())
	{
		cout << "The list is empty.\n";
		return;
	}
	Node* currNode = head;
	Node* nextNode;
	Node* delNode;
	// For the first node
	while (currNode != nullptr && currNode-> value == delValue) 
	{
		delNode = head;
		head = currNode-> next;
		currNode = head;
		delete delNode;
	}
	// traversing the list to check other nodes
	while (currNode != nullptr)
	{
		nextNode = currNode-> next;
		if (nextNode != nullptr && nextNode-> value == delValue)
		{
			delNode = currNode-> next;
			currNode-> next = nextNode-> next;
			delete delNode;
		}
		else
			currNode = nextNode;
	} 
}

void LinkedList:: freeList() 
{
	Node* curr = head;
	Node* next;
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
	Node* curr = head;
	Node* next = nullptr;
	Node* prev = nullptr;
	while (curr != nullptr)
	{
		next = curr-> next;
		curr-> next = prev;
		prev = curr;
		curr = next;
	}
	head = prev; 
}

LinkedList:: Node* LinkedList:: reverseRecurseUtil( Node* currentNode, Node* nextNode)
{
	Node* ret; 
	// when currentNode reaches at last.
	if (currentNode == nullptr) 
		return nullptr;
	// when currentNode points at the last node.
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

void LinkedList:: removeDuplicate()
{
	Node* curr = head;
	Node* delNode;
	while (curr != nullptr)
	{
		if (curr-> next != nullptr && curr-> value == curr-> next-> value)
		{
			delNode = curr-> next;
			curr-> next = curr-> next-> next;
			delete delNode;
		}
		else
		{
			curr = curr-> next;
		}
	} 
}

LinkedList* LinkedList:: CopyListReversed()
{
	Node* tempNode = nullptr;
	Node* tempNode2 = nullptr;
	Node* curr = head;
	// traversing list to the end.
	while (curr != nullptr)
	{
		tempNode2 = new Node(curr-> value, tempNode);
		curr = curr-> next;
		tempNode = tempNode2;
	}
	LinkedList* ll2 = new LinkedList();
	ll2-> head = tempNode;
	return ll2;
}

LinkedList* LinkedList:: CopyList()
{
	Node* headNode = nullptr;
	Node* tailNode = nullptr;
	Node* tempNode = nullptr;
	Node* curr = head;
	// If the list is empty
	if (curr == nullptr)
	{
		LinkedList* ll2 = new LinkedList();
		ll2-> head = nullptr;
		return ll2;
	}
	headNode = new Node( curr-> value, nullptr);
	tailNode = headNode;
	curr = curr-> next;
	while (curr != nullptr)
	{
		tempNode = new Node( curr-> value, nullptr);
		tailNode-> next = tempNode;
		tailNode = tempNode;
		curr = curr-> next;
	}
	LinkedList* ll2 = new LinkedList();
	ll2-> head = headNode;
	return ll2;
}

bool LinkedList:: compareList( Node* head1, Node* head2) 
{
	// If both of the linked list has only one node.
	if (head1 == nullptr && head2 == nullptr)
	{
		return true;
	} // Comparing VALUES and ADDRESS of each node.
	else if (( head1 == nullptr) || (head2 == nullptr) || (head1-> value != head2-> value))
	{
		return false;
	}
	else
	{
		return compareList( head1-> next, head2-> next);
	}
}

bool LinkedList:: compareList( LinkedList* ll)
{
	return compareList( head, ll-> head); 
}

int LinkedList:: nthNodeFromBegining( int index)
{
	// Check if index > size.
	if (index > size() || index < 1)
	{
		cout<< "Too few Nodes.";
	}
	int count = 0;
	Node* curr = head;
	while (curr != nullptr && count < index - 1)
	{
		count++;
		curr = curr-> next;
	}
	return curr-> value; 
}

int LinkedList:: nthNodeFromEnd( int index) 
{
	int size = findLength(); 
	// Check for zero elements.
	if (size != 0 && size < index) 
	{ 
		cout<< "Too few Nodes.";
	}
	int startIndex; 
	startIndex = size - index + 1; 
	return nthNodeFromBegining( startIndex); 
}

// Using Smart Pointer Fast Pointer Approach
bool LinkedList:: loopDetect()
{
	Node* slowPtr;
	Node* fastPtr;
	slowPtr = fastPtr = head;
	while (fastPtr-> next != nullptr && fastPtr-> next-> next != nullptr)
	{
		slowPtr = slowPtr-> next;
		fastPtr = fastPtr-> next-> next;
		if (slowPtr == fastPtr)
		{
			cout << "Loop found" << endl;
			return true;
		}
	}
	cout << "Loop not found" << endl;
	return false; 
}

// Not used much since it involves alteriing linked list.
bool LinkedList:: reverseListLoopDetect() 
{
	Node* tempHead = head;
	reverse();
	if (tempHead == head)
	{
		reverse();
		cout << "Loop found" << endl;
		return true;
	}
	else
	{
		reverse();
		cout << "Loop not found" << endl;
		return false;
	}
}

int LinkedList:: loopTypeDetect()
{
	Node* slowPtr;
	Node* fastPtr;
	slowPtr = fastPtr = head;
	while (fastPtr-> next != nullptr && fastPtr-> next-> next != nullptr)
	{
		if (head == fastPtr-> next || head == fastPtr-> next-> next)
		{
			cout << "Circular list loop found." << endl;
			return 2;
		}
		slowPtr = slowPtr-> next;
		fastPtr = fastPtr-> next-> next;
		if (slowPtr == fastPtr)
		{
			cout << "Loop found" << endl;
			return 1;
		}
	}
	cout << "Loop not found" << endl;
	return 0;
}

void LinkedList:: removeLoop() 
{
	Node* loopPoint = loopPointDetect(); 
	if (loopPoint == nullptr) 
	{ 
		return; 
	} 
	Node* firstPtr = head; 
	if (loopPoint == head) 
	{ 
		while (firstPtr-> next != head) 
		{  
			firstPtr = firstPtr-> next; 
		} 
		firstPtr-> next = nullptr; 
		return; 
	}
	Node* secondPtr = loopPoint; 
	while (firstPtr-> next != secondPtr-> next) 
	{
		firstPtr = firstPtr-> next; 
		secondPtr = secondPtr-> next; 
	}
	secondPtr-> next = nullptr; 
}

LinkedList:: Node* LinkedList:: loopPointDetect() 
{ 
	Node* slowPtr; 
	Node* fastPtr; 
	slowPtr = fastPtr = head; 
	while (fastPtr-> next != nullptr && fastPtr-> next-> next != nullptr) 
	{ 
		slowPtr = slowPtr-> next; 
		fastPtr = fastPtr-> next-> next; 
		if (slowPtr == fastPtr) 
		{  
			return slowPtr;
		} 
	} 
	return nullptr; 
}

LinkedList:: Node* LinkedList:: findIntersection( Node* head, Node* head2) 
{
	int l1 = 0;
	int l2 = 0;
	Node* tempHead = head;
	Node* tempHead2 = head2;
	while (tempHead != nullptr)
	{
		l1++;
		tempHead = tempHead-> next;
	}
	while (tempHead2 != nullptr)
	{
		l2++;
		tempHead2 = tempHead2-> next;
	}
	int diff;
	if (l1 < 12)
	{
		Node* temp = head;
		head = head2;
		head2 = temp;
		diff = l2 - l1;
	}
	else
	{
		diff = l1 - l2;
	}
	for (; diff > 0; diff--)
	{
		head = head-> next;
	}
	while (head != head2)
	{
		head = head-> next;
		head2 = head2-> next;
	}
	return head; 
}

int LinkedList:: findLength() 
{
	Node* curr = head;
	int count = 0;
	while (curr != nullptr)
	{
		count++;
		curr = curr-> next;
	}
	return count; 
}

int main()
{
	LinkedList* ll = new LinkedList();
	LinkedList* l2, l3;
	LinkedList* l4 = new LinkedList();
	
	l4->addHead(1);
	l4->addHead(2);
	l4->addHead(3);
	l4->addHead(4);
	int ch, opt = 0;
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
	cout<<"\n12. Recursively reverse a single Linked List.		</>";
	cout<<"\n13. Remove Duplicates from Linked List.";
	cout<<"\n14. Copy the content of linked list in another linked list in reverse order.";
	cout<<"\n15. Copy the content of given linked list into another linked list.";
	cout<<"\n16. Compare two given list.";
	cout<<"\n17. Find Length.";
	cout<<"\n18. Find Nth node from beginning.";
	cout<<"\n19. Find Nth node from end.";
	cout<<"\n20. Detect a loop using Slow Pointer Fast Pointer Approach.";
	cout<<"\n21. Detect loop using Reverse List Approach.";
	cout<<"\n22. Detect loop type using slow pointer fast pointer approach.";
	cout<<"\n23. Remove loop in Linked List.";
	cout<<"\n24. Find intersection in Linked List.";
	cout<<"\n25. Exit.";

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

				break;
			case 4:
				cout << "\nEnter the element you want to insert in sorted order: ";
				cin >> val;
				ll->sortedInsert(val);
				break;
			case 5:
				cout << "\nElements in the linked list are: ";
				ll->print();
				break;
			case 6:
				cout << "\nEnter the element you want to search: ";
				cin >> val;
				if(ll->isPresent(val))
					cout<<"\nElement is present in the list.";
				else	
					cout<<"\nElement is not present in the list.";
				break;
			case 7:
				val = ll->removeHead();
				if (val != NULL)
					cout << "\nElement removed from head is " << val;
				break;
			case 8:
				cout << "\nEnter the value stored in node you want to delete: ";
				cin >> val;
				res = ll->deleteNode(val);
				if(res)
					cout<<"\nNode deleted successfully.";
				else	
					cout<<"\nNo Node contains the value "<< val<<".";
				break;
			case 9:
				cout << "\nEnter the value stored in nodes you want to delete: ";
				cin >> val;
				/*res = */ll->deleteNodes(val);
				//if(res)
					cout<<"\nAll Nodes deleted successfully.";
				//else	
				//	cout<<"\nNo Node contains the value "<< val<<".";
				break;
			case 10:
				ll->freeList();
				cout<<"\nLinked List deleted successfully.";
				break;
			case 11:
				ll->reverse();
				cout << "\nAfter reversal, elements in the linked list are: ";
				ll->print();
				break;
			case 12:
				ll->reverseRecurse();
				cout << "\nAfter recursive reversal, elements in the linked list are: ";
				ll->print();
				break;
			case 13:
				ll->removeDuplicate();
				cout << "\nAfter removing all duplicates, elements in the linked list are: ";
				ll->print();
				break;
			case 14:
				l2 = ll->CopyListReversed();
				cout << "\nAfter reversing and copying, elements in 2nd linked list are: ";
				l2->print();
				break;
			case 15:
				l2 = ll->CopyList();
				cout << "\nAfter copying in 2nd linked list, elements in 2nd linked list are: ";
				l2->print();
				break;
			case 16:
				res = ll->compareList(l4);
				if (res)
					cout<<"\nBoth linked list are the same.";
				else
					cout<<"\nBoth linked list are different.";
				break;
			case 17:
				val = ll-> findLength();
				cout<< "\nThe size of Linked List is "<< val;
				break;
			case 18:
				cout << "\nEnter which node you want to access from begining? ";
				cin >> val;
				val = ll->nthNodeFromBegining(val);
				cout << "\nYour value is "<<val;
				break;
			case 19:
				cout << "\nEnter which node you want to access from end? ";
				cin >> val;
				val = ll->nthNodeFromEnd(val);
				cout << "\nYour value is "<<val;
				break;
			case 20:
				res = ll->loopDetect();
				if (res)
					cout<<"\nLoop Detected.";
				else
					cout<<"\nNo loop found.";
				break;
			case 21:
				res = ll-> reverseListLoopDetect();
				if (res)
					cout<<"\nLoop Detected.";
				else
					cout<<"\nNo loop found.";
				break;
			case 22:
				val = ll -> loopTypeDetect();
				break;
			case 23:
				ll->removeLoop();
				cout<<"\nLoop removed.";
				break;
			case 24:
			/*
				l3 = ll->findIntersection( ll, l2);
				cout<<"\nIntersection point is: ";
				l3 -> print();
			*/	break;
			case 25:
				opt = 25;
				break;
			default:cout<<"\nPlease enter the correct choice: ";
		}
	}while(opt != 25);
	
	return 0;
}
