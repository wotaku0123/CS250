#include "AnyList.h"

using namespace std;

void AnyList::insertFront(int newData)
{	
	first = new Node(newData, first);
	++count;
}

// 2. Insert a new node, storing a given value, at the end of the calling object.
void AnyList::insertEnd(int newData)
{
	Node* current = first;

	while(current->getNext() != nullptr)
	{
		current = current->getNext();
	}

	current->setNext(new Node(newData, nullptr));
	++count;
}

// 4. Insert a new node, storing a given value, before the last node of the calling object.
void AnyList::insertBeforeLast(int newData)
{
	Node* current = first;
	while(current->getNext()->getNext() != nullptr)
	{
		current = current->getNext();
	}

	current->setNext(new Node(newData, current->getNext()));
	++count;
}

// 6. Given two int parameters, value1 and value2, insert a new node, storing value1, after the node that stores value2.
void AnyList::insertAfterTarget(int value1, int value2)
{
	Node* current = first;
	bool found = false;

	while(current->getNext() != nullptr)
	{
		if(current->getData() == value2)
		{
			current->setNext(new Node(value2, current->getNext()));
			++count;
			found = true;
		}
		else
		{
			current = current->getNext();
		}
	}

	if(!found)
	{
		cout << "No numbers matched with value2" << endl;
	}
}

void AnyList::print() const
{
	if (first == nullptr) 
	// Check if the list is empty.
	// You can also use: if (count == 0)
		cerr << "List is empty.";  
		// Use cerr, instead of cout. Why?
	else
	{
        	Node *current = first;   
		// Create a pointer to traverse the list.		
		// This pointer will point to the first node in the list.

		while (current != nullptr)	
		// While the current pointer is NOT a nullptr,
		// that is, while the current pointer has not reached  
		// the end of the list.
		{	                        
			// Output the data. 
			cout << current->getData() << " "; 
			// Move the pointer current forward.
			current = current->getNext();                         
		}		
	}
}

// This function does not delete the 
// list object; it ONLY deletes the nodes.
void AnyList::clearList()
{ 	
	Node  *temp = first; 	
	// Pointer to delete the node, which	
	// starts by pointing to the first node.
	
	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}

	// Update the count outside the loop.
   	count = 0;
}

AnyList::~AnyList()
{
	if (first != nullptr)
		 clearList();
}