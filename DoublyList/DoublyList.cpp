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

// 38. Swap the value of the first node of the calling object with the value of the first node of the parameter object
void DoublyList::swapFirstValueOfCallAndParam(DoublyList& doublyList)
{
    int temp = first->getData();
    
    first->setData(doublyList.first->getData());
    doublyList.first->setData(temp);
    
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



