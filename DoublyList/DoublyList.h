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

	// 10. Delete the node before-last of the calling object.
	void deleteBeforeLast();

	// 24. Swap the second node with the last node.
	void swapSecondLast();

	// 35. Rotate a list to the left (or right) by rotating the nodes. You will need to reset pointers.
	void rotateLeft();

	// 38. Swap the value of the first node of the calling object with the value of the first node of the parameter object
	void swapFirstValueOfCallAndParam(DoublyList&);

	// 40. Swap the value of the first node of the calling object with the value of the last node of the parameter object.
	void swapCallingFirstAndParameterLast(DoublyList&);

	// 42. Swap the value of the first node of the calling object with the value of the second node of the parameter object.
	void swapCallingFirstAndParameterSecond(DoublyList&);

	// 44. Swap the value of the first node of the calling object with the value of the before last of the parameter object.
	void swapCallingFirstAndParameterBeforeLast(DoublyList&);

	// 66. Swap the value of the node before last of the calling object with the value of the second node of the parameter object.
	void swapCallingBeforeLastParameterSecond(DoublyList&);

	// 80. Swap calling object and parameter object. Think how to implement this one efficiently without any loops.
	void swapCallingAndParameter(DoublyList&);

	// Lab 2, delete every 3 numbers and get the dinner
	void selectSuitor();


	// lab 3
	void rotateNodesRight(int);
	
	void clearList();
	~DoublyList();

	// void selectSuitor();

private:
    // Pointer to the first node in the list.
	DLLNode*first;
    // Pointer to the last node in the list.
	DLLNode*last;
	// Number of nodes in the list.
	int count;			
};

#endif