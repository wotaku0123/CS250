#include "DoublyList.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

    DoublyList intList;

    intList.insertFront(6);
    intList.insertFront(5);
    intList.insertFront(4);
    intList.insertFront(3);
    intList.insertFront(2);
    intList.insertFront(1);

    cout << "The list has ";
    intList.printForward();
    cout << " " << endl;

    intList.selectSuitor();

    return 0;
}