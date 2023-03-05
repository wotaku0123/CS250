#ifndef ANYLIST_H
#define ANYLIST_H

#include<iostream>
#include <string> // Need to include for nullptr.			

class Node
{
	public:
		Node() : data(0), next(nullptr) {}
		Node(int theData, Node *newNext) 
			: data(theData), next(newNext){}
		Node* getNext() const { return next; }
		int getData( ) const { return data; }
		void setData(int theData) { data = theData; }
		void setNext(Node *newNext) 
			{ next = newNext; }
		~Node(){}
	private:
		int data;		
		Node *next; // Pointer that points to next node.
};


class AnyList
{
	public:
		AnyList() : first(nullptr), count(0) {}

		void insertFront(int);	

		// 2. Insert a new node, storing a given value, at the end of the calling object.
		void insertEnd(int);

		// 4. Insert a new node, storing a given value, before the last node of the calling object.
		void insertBeforeLast(int);

		// 6. Given two int parameters, value1 and value2, insert a new node, storing value1, after the node that stores value2.
		void insertAfterTarget(int, int);

		// 8. Delete the second node of the calling object.
		void deleteSecond();

		// 10. Delete the node before-last of the calling object.
		void deleteBeforeLast();

		// 12. Replace the value of the last node of the calling object with the value passed by the parameter.
		void replaceLast(int);

		// 14.Replace the value of the second-to-last node of the calling object with the value passed by the parameter.
		void replaceSecondToLast(int);

		// 16. Given two int parameters, oldValue and newValue, replace all occurrences of the oldValue with the newValue.
		void replaceOldToNew(int, int);

		// 18. Swap the first node with the last node.
		void swapFirstLast();

		// 20. Swap the first node with the second node.
		void swapFirstSercond();

		// 22. Swap the first node with the node before last.
		void swapFirsAndBeforeLast();

		// 24. Swap the second node with the last node.
		void swapSecondLast();

		// 44. Swap the value of the first node of the calling object with the value of the before last of the parameter object.
		void swapCallingFirstAndParameterBeforeLast(AnyList&);

		// 46. Swap the value of the second node of the calling object with the value of the first node of the parameter object.
		void swapCallingSecondAndParameterFirst(AnyList&);

		// 76. Swap the value of the node before last of the calling object with the value of the second node of the parameter object.
		void swapCallingBeforeLastAndParametersecond(AnyList&);

	
		//Lab3
		void rotateNodesLeft(int);

		void print() const;

		void clearList();
		~AnyList();

	private:
		Node *first;
		// Pointer to point to the first node in the list.
		int count;
		// Variable to keep track of number of nodes in the list.
};

#endif