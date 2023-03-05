#include <iostream>
#include <string>

#include "DoublyList.h"
using namespace std;

void DoublyList::insertFront(int newData)
{
    if (first == nullptr)
    {
        first = new DLLNode(newData, nullptr, nullptr);
        last = first;	
        // Common error: Forgetting to reset pointer last.
    }
    else
    {
        first = new DLLNode(newData, nullptr, first);
        first->getNext()->setPrev(first);
        // Common error: Forgetting to connect pointer 
        // prev of what is now the second node to the 
        // new first node.
    }

    ++count;
}

void DoublyList::printForward() const
{
    DLLNode* current = first;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getNext();
    }
}

void DoublyList::printReverse() const
{
    DLLNode* current = last;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getPrev();
    }
}

// 24. Swap the second node with the last node.
void DoublyList::swapSecondLast()
{
    DLLNode* temp = last;
    DLLNode* second = first->getNext();

    last->setPrev(first);
    last->setNext(second->getNext());
    first->setNext(temp);
    second->getNext()->setPrev(temp);

    second->setNext(nullptr);
    second->setPrev(last->getPrev());
    last->getPrev()->setNext(second);
}

// 38. Swap the value of the first node of the calling object with the value of the first node of the parameter object
void DoublyList::swapFirstValueOfCallAndParam(DoublyList& doublyList)
{
    int temp = first->getData();
    
    first->setData(doublyList.first->getData());
    doublyList.first->setData(temp);
    
}

// lab 3
void DoublyList::rotateNodesRight(int numOfTimes)
{
    for(int i = 0; i < numOfTimes; ++i)
    {
        DLLNode* beforeLast = last->getPrev();

        beforeLast->setNext(nullptr);
        last->setPrev(nullptr);

        last->setNext(first);
        first->setPrev(last);

        first = last;
        last = beforeLast;

    }
}

// 40. Swap the value of the first node of the calling object with the value of the last node of the parameter object.
void DoublyList::swapCallingFirstAndParameterLast(DoublyList& doublyList)
{
    DLLNode* current = first->getNext();
    first->setNext(nullptr);
    current->setPrev(doublyList.last);
    doublyList.last->setNext(current);

    doublyList.last->getPrev()->setNext(first);
    first->setPrev(doublyList.last->getPrev());

    current = current->getPrev();

    doublyList.last  = first;
    first = current;
}

void DoublyList::clearList()
{ 	
    DLLNode* temp = first;

    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }

    last = nullptr;		
    // Don't forget to reset pointer last to nullptr.
    count = 0;
}

DoublyList::~DoublyList()
{
    if (first != nullptr)
        clearList();
}

void DoublyList::selectSuitor()
{
   first->setPrev(last);
   last->setNext(first);
   DLLNode* current = first;
   
   while(count > 1)
   {
      
      for(int i = 0; i < 2; ++i)
      {
         current = current->getNext();
      }
      cout << endl;
      cout << "Suitor " << current->getData() << " will be eliminated!";
      current->getPrev()->setNext(current->getNext());
      current->getNext()->setPrev(current->getPrev());
      
      DLLNode *nodeToDelete = current;
      delete nodeToDelete;
      nodeToDelete = nullptr;
      
      if(count > 1) current = current->getNext();
      --count;
      
   }
   
   first = current;
   last = current;
   first->setPrev(nullptr);
   last->setNext(nullptr);
   
}



