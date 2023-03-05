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

// 8. Delete the second node of the calling object.
void AnyList::deleteSecond()
{
	Node* current = first->getNext();

	first->setNext(current->getNext());
	
	delete current;
	current = nullptr;
	
	--count;
}

// 10. Delete the node before-last of the calling object.
void AnyList::deleteBeforeLast()
{
	Node* current = first->getNext();
	Node* tailNode = first;

	while(current->getNext()->getNext() != nullptr)
	{
		current = current->getNext();
		tailNode = tailNode->getNext();
	}

	tailNode->setNext(current->getNext());
	delete current;
	current = nullptr;
	--count;
}

// 12. Replace the value of the last node of the calling object with the value passed by the parameter.
void AnyList::replaceLast(int newData)
{
	Node* current = first;

	while(current->getNext() != nullptr)
	{
		current = current->getNext();
	}

	current->setData(newData);
}
// 14.Replace the value of the second-to-last node of the calling object with the value passed by the parameter.
void AnyList::replaceSecondToLast(int newData)
{
	Node* current = first;

	while(current->getNext() != nullptr)
	{
		current = current->getNext();
		current->setData(newData);
	}
}

// 16. Given two int parameters, oldValue and newValue, replace all occurrences of the oldValue with the newValue.
void AnyList::replaceOldToNew(int oldValue, int newValue)
{
	Node* current = first;

	while(current->getNext() != nullptr)
	{
		if(current->getData() == oldValue)
		{
			current->setData(newValue);
		}

		current = current->getNext();
	}
}

// 18. Swap the first node with the last node.
void AnyList::swapFirstLast()
{
	Node* last = first;

	while(last->getNext() != nullptr)
	{
		last = last->getNext();
	}

	int temp = first->getData();
	first->setData(last->getData());
	last->setData(temp);
}

// 20. Swap the first node with the second node.
void AnyList::swapFirstSercond()
{
	Node* second = first->getNext();
	first->setNext(second->getNext());
	second->setNext(first);
	first = second;
}

// 22. Swap the first node with the node before last.
// void AnyList::swapFirsAndBeforeLast()
// {
// 	Node* beforeLast = first->getNext();
// 	Node* temp = first;

// 	while(beforeLast->getNext()->getNext() != nullptr)
// 	{
// 		beforeLast = beforeLast->getNext();
// 		temp = temp->getNext();
// 	}
// 	first->setNext(beforeLast->getNext());
// 	temp->setNext(temp);

// 	// first = beforeLast;

// }


// 44. Swap the value of the first node of the calling object with the value of the before last of the parameter object.
void AnyList::swapCallingFirstAndParameterBeforeLast(AnyList& anyList)
{
	Node* trailNode = anyList.first;
	Node* parameterCurrent = trailNode->getNext();
	Node* current = first->getNext();

	while(parameterCurrent->getNext()->getNext() != nullptr)
	{
		trailNode = trailNode->getNext();
		parameterCurrent = parameterCurrent->getNext();
	}

	trailNode->setNext(first);
	first->setNext(parameterCurrent->getNext());
	parameterCurrent->setNext(current);

	first = parameterCurrent;


}

// 46. Swap the value of the second node of the calling object with the value of the first node of the parameter object.
void AnyList::swapCallingSecondAndParameterFirst(AnyList& anyList)
{
	Node* trailNode = first->getNext();
	Node* current = trailNode->getNext();
	trailNode->setNext(anyList.first->getNext());
	first->setNext(anyList.first);
	anyList.first->setNext(current);

	anyList.first = trailNode;
}

// 76. Swap the value of the node before last of the calling object with the value of the second node of the parameter object.
void AnyList::swapCallingBeforeLastAndParametersecond(AnyList& anyList) 
{
	Node* trailNode = first;
	Node* current = trailNode->getNext();
	Node* parameterTrailNode = anyList.first->getNext();
	Node* parameterCurrent = parameterTrailNode->getNext();
	Node* last = current->getNext();

	while(current->getNext()->getNext() != nullptr)
	{
		trailNode = trailNode->getNext();
		current = current->getNext();
		last = last->getNext();
	}

	anyList.first->setNext(current);
	current->setNext(parameterCurrent);
	trailNode->setNext(parameterTrailNode);
	parameterTrailNode->setNext(last);
}
// Lab 3
void AnyList::rotateNodesLeft(int numOfTimes)
{
	for(int i = 0; i < numOfTimes; ++i)
	{
		Node* last = first;
		Node* second = first->getNext();

		while(last->getNext() != nullptr)
		{
			last = last->getNext();
		}

		first->setNext(nullptr);
		last->setNext(first);
		
		first = second;
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