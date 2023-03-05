#include "AnyList.h"

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// vector<vector<int>> data; //= {
	// {25, 76, 35, 67, 15, 98},
	// {1, 2, 3, 4, 5, 6, 7, 8, 9},
	// {10, 20},
	// {34, 56, 78, 12, 89, 34, 76, 28, 54, 22, 41},
	// {123, 873, 619},

	// };

	vector<vector<int> > data;
	vector<int> data1;
	data1.push_back(25);
	data1.push_back(76);
	data1.push_back(35);
	data1.push_back(67);
	data1.push_back(15);
	data1.push_back(98);

	vector<int> data2;
	for(int i = 1; i < 10; ++i)
	{
		data2.push_back(i);
	}

	vector<int> data3;
	data3.push_back(10);
	data3.push_back(20);

	vector<int> data4;
	data4.push_back(34);
	data4.push_back(56);
	data4.push_back(78);
	data4.push_back(12);
	data4.push_back(89);
	data4.push_back(34);
	data4.push_back(76);
	data4.push_back(28);
	data4.push_back(54);
	data4.push_back(22);
	data4.push_back(41);

	vector<int> data5;
	data5.push_back(123);
	data5.push_back(873);
	data5.push_back(619);

	data.push_back(data1);
	data.push_back(data2);
	data.push_back(data3);
	data.push_back(data4);
	data.push_back(data5);


	vector<int> nodesToRotate; //= { 2, 3, 1, 9, 2 };
	nodesToRotate.push_back(2);
	nodesToRotate.push_back(3);
	nodesToRotate.push_back(1);
	nodesToRotate.push_back(9);
	nodesToRotate.push_back(2);

	/* Uncomment section below when testing AnyList::rotateNodesLeft() */
	{
		AnyList singlyList;
		int vectorSize = static_cast<int>(data.size());
		for (int i = 0; i < vectorSize; ++i)
		{
			int innerSize = static_cast<int>(data[i].size());
			for (int j = innerSize - 1; j >= 0; --j)
				singlyList.insertFront(data[i].at(j));
			cout << "Rotate left: " << nodesToRotate[i] << "\n";	
			cout << "       List is: ";
			singlyList.print();
			cout << "\n";						
			singlyList.rotateNodesLeft(nodesToRotate[i]);
			cout << "After rotating: "; 
			singlyList.print();
			cout << "\n\n";
			singlyList.clearList();
		}
	}

	cout << "----------------------\n";
	
	// AnyList myList;

	// myList.insertFront(8);
	// myList.insertFront(7);
	// myList.insertFront(4);
	// myList.insertFront(2); 

	// cout << "Inserted: 2 4 7 8\n";
	// cout << "List is: ";

    // myList.rotateNodesLeft(3);
    // myList.print();
	return 0;
}