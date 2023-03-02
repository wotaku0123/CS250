#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>

class DLLNode
{
public:
	DLLNode() : data(0), prev(nullptr), next(nullptr) {}
	DLLNode(int theData, DLLNode* prevLink, DLLNode* nextLink)
		: data(theData), prev(prevLink), next(nextLink) {}
	int getData() const { return data; }
	DLLNode* getPrev() const { return prev; }
	DLLNode* getNext() const { return next; }
	void setData(int theData) { data = theData; }
	void setPrev(DLLNode* prevLink) { prev = prevLink; }
	void setNext(DLLNode* nextLink) { next = nextLink; }
	~DLLNode(){}
private:
	int data;   // To simplify, we are using only one piece of data.
	DLLNode* prev;
	DLLNode* next;
};

class DoublyList
{
public:
	DoublyList() : first(nullptr), last(nullptr), count(0) {}

	void insertFront(int newData);

	void printForward() const;
	void printReverse() const;
	
	void clearList();
	~DoublyList();

	void selectSuitor();

private:
    // Pointer to the first node in the list.
	DLLNode*first;
    // Pointer to the last node in the list.
	DLLNode*last;
	// Number of nodes in the list.
	int count;			
};

#endif