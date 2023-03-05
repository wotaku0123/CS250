#include "DoublyList.h"

#include <iostream>
#include <vector>

using namespace std;

int main(){

// vector<vector<int> > data;
// vector<int> data1;
// data1.push_back(25);
// data1.push_back(76);
// data1.push_back(35);
// data1.push_back(67);
// data1.push_back(15);
// data1.push_back(98);

// vector<int> data2;
// for(int i = 1; i < 10; ++i)
// {
// 	data2.push_back(i);
// }

// vector<int> data3;
// data3.push_back(10);
// data3.push_back(20);

// vector<int> data4;
// data4.push_back(34);
// data4.push_back(56);
// data4.push_back(78);
// data4.push_back(12);
// data4.push_back(89);
// data4.push_back(34);
// data4.push_back(76);
// data4.push_back(28);
// data4.push_back(54);
// data4.push_back(22);
// data4.push_back(41);

// vector<int> data5;
// data5.push_back(123);
// data5.push_back(873);
// data5.push_back(619);

// data.push_back(data1);
// data.push_back(data2);
// data.push_back(data3);
// data.push_back(data4);
// data.push_back(data5);


// vector<int> nodesToRotate; 
// nodesToRotate.push_back(2);
// nodesToRotate.push_back(3);
// nodesToRotate.push_back(1);
// nodesToRotate.push_back(9);
// nodesToRotate.push_back(2);


// 		DoublyList doublyList;
// 		int vectorSize = static_cast<int>(data.size());
// 		for (int i = 0; i < vectorSize; ++i)
// 		{
// 			int innerSize = static_cast<int>(data[i].size());
// 			for (int j = innerSize - 1; j >= 0; --j)
// 				doublyList.insertFront(data[i].at(j));
// 			cout << "Rotate right: " << nodesToRotate[i] << "\n";
// 			cout << "       List is: ";
// 			doublyList.printForward();
// 			cout << "\n";
// 			doublyList.rotateNodesRight(nodesToRotate[i]);
// 			cout << "After rotating:";
// 			cout << "\n  Print forward: ";
// 			doublyList.printForward();
// 			cout << "\nPrint backwards: ";
// 			doublyList.printReverse();
// 			cout << "\n\n";
// 			doublyList.clearList();
// 		}
	
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

    cout << "The intList has ";
    intList.printForward();
    cout << " " << endl;
    cout << "The dllList has ";
    dllList.printForward();
    cout << " " << endl;


    cout << " " << endl;

    intList.swapCallingFirstAndParameterSecond(dllList);

    cout << "The intList has ";
    intList.printForward();
    cout << " " << endl;
    cout << "The dllList has ";
    dllList.printForward();
    cout << " " << endl;

    return 0;
}