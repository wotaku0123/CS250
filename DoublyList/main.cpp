#include "DoublyList.h"

#include <iostream>

using namespace std;

int main(){

    DoublyList intList;
    DoublyList dllList;

    intList.insertFront(6);
    intList.insertFront(5);
    intList.insertFront(4);
    intList.insertFront(3);
    intList.insertFront(2);
    intList.insertFront(1);

    dllList.insertFront(10);
    dllList.insertFront(8);
    dllList.insertFront(6);
    dllList.insertFront(4);
    dllList.insertFront(2);

    cout << "The list has ";
    intList.printForward();
    cout << " " << endl;

    cout << "The list has ";
    dllList.printForward();
    cout << " " << endl;

    intList.swapFirstValueOfCallAndParam(dllList);

    cout << "The list has ";
    intList.printForward();
    cout << " " << endl;

    cout << "The list has ";
    dllList.printForward();
    cout << " " << endl;

    return 0;
}