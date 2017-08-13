#include<iostream>
#include<conio.h>
#include<vector>
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
		//	virtual int removeHead();
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

void LinkedList:: addTail(int value) 
{
	Node *newNode = new Node(value, nullptr);
	Node *curr = head;
	if (head == nullptr)
		head = newNode;
	while (curr-> next != nullptr)
	curr = curr-> next;
	curr-> next = newNode; 
}

void LinkedList:: print() 
{
	Node *temp = head;
	while (temp != nullptr)
	{
		cout << temp-> value << " ";
		temp = temp-> next;
	}
	cout << endl; 
}

int main() 
{
	LinkedList ll = LinkedList();

	cout<<"\n1. Insert at the begining / Head of Linked List.";
	cout<<"\n2. Insert at the end / Tail of Linked List.";
	cout<<"\n3. Insert at the Nth position of Linked List.";
	cout<<"\n4. Insert in sorted order in Linked List.";
	cout<<"\n5. Print all elements of Linked List.";
	cout<<"\n6. Search an element in Linked List.";
	cout<<"\n7. Delete first element in Linked List.";
	cout<<"\n8. Delete node from Linked List given its value.";
	cout<<"\n9. Delete all the occurences of particular value in Linked List.";
	cout<<"\n10. Delete a single Linked List.";
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

	ll.addHead(1); 
	ll.addHead(2);
	ll.addHead(3);
	ll.addHead(3);
	ll.print(); 
	cout<<"\n"<<ll.size();

	return 0;
}
