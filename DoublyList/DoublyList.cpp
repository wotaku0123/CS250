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

// 10. Delete the node before-last of the calling object.
void DoublyList::deleteBeforeLast()
{
    DLLNode* current = last->getPrev();
    current->getPrev()->setNext(last);
    last->setPrev(current->getPrev());

    delete current;
    current = nullptr;

    --count;
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

// 42. Swap the value of the first node of the calling object with the value of the second node of the parameter object.
void DoublyList::swapCallingFirstAndParameterSecond(DoublyList& doublyList)
{
    DLLNode* current = first->getNext();
    DLLNode* parameterCurrent = doublyList.first->getNext();

    doublyList.first->setNext(first);
    first->setPrev(doublyList.first);
    first->setNext(parameterCurrent->getNext());
    parameterCurrent->getNext()->setPrev(first);

    parameterCurrent->setPrev(nullptr);
    parameterCurrent->setNext(current);
    current->setPrev(parameterCurrent);

    first = parameterCurrent;
}

// 44. Swap the value of the first node of the calling object with the value of the before last of the parameter object.
void DoublyList::swapCallingFirstAndParameterBeforeLast(DoublyList& doublyList)
{
    DLLNode* current = first->getNext();
    DLLNode* beforeLast = doublyList.last->getPrev();

    first->setPrev(beforeLast->getNext());
    beforeLast->getPrev()->setNext(first);
    first->setNext(last);
    last->setPrev(first);

    current->setPrev(beforeLast);
    beforeLast->setNext(current);
    beforeLast->setPrev(nullptr);

    first = beforeLast;
}

// 66. Swap the value of the node before last of the calling object with the value of the second node of the parameter object.
void DoublyList::swapCallingBeforeLastParameterSecond(DoublyList& doublyList)
{
    DLLNode* beforeLast = last->getPrev();
    DLLNode* second = doublyList.first->getNext();

    doublyList.first->setNext(beforeLast);
    beforeLast->setNext(second->getNext());
    beforeLast->getNext()->setPrev(second);

    second->setPrev(beforeLast->getPrev());
    beforeLast->getPrev()->setNext(second);
    second->setNext(last);

    last->setPrev(second);
    beforeLast->setPrev(doublyList.first);

}

// 80. Swap calling object and parameter object. Think how to implement this one efficiently without any loops.
void DoublyList::swapCallingAndParameter(DoublyList& doublyList)
{
    DLLNode* temp = first;
    first = doublyList.first;
    doublyList.first = temp;

    temp = last;
    last = doublyList.last;
    doublyList.last = temp;

    temp = nullptr;
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



