#include "AnyList.h"

#include <iostream>
using namespace std;

int main()
{
	AnyList myList;

	myList.insertFront(8);
	myList.insertFront(7);
	myList.insertFront(4);
	myList.insertFront(2); 

	cout << "Inserted: 2 4 7 8\n";
	cout << "List is: ";

    myList.insertAfterTarget(1, 4);
    myList.print();
	return 0;
}