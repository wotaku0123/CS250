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