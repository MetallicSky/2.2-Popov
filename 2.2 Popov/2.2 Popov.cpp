#include "pch.h"
#include "RBTree.h"
#include "List.h"
#include <iostream>
#include <Windows.h>
#include <exception>


using namespace std;


int main()
{
	RBTree<int> test;
	/*for (int i = 0; i < 10; i++)
	{
		int number = rand() % 100;
		cout << "\n\n step " << number << "\n\n";
		test.insert(number);
		test.print();
	}*/
	test.insert(41);
	test.print();
	cout << "\n\n";
	test.insert(67);
	test.print();
	cout << "\n\n";
	test.insert(34);
	test.print();
	cout << "\n\n";
	test.insert(0);
	test.print();
	cout << "\n\n";
	test.insert(69);
	test.print();
	cout << "\n\n";
	test.insert(24);
	test.print();
	cout << "\n\n";
	test.insert(67);
	test.print();
	cout << "\n\n";
	test.insert(67);
	test.print();
	cout << "\n\n";
	test.insert(78);
	test.print();
	cout << "\n\n";
	test.insert(58);
	test.print();
	cout << "\n\n";
	test.insert(62);
	test.print();
	cout << "\n\n";
	test.insert(64);
	test.print();
	cout << "\n\n";
	int number = 67;
	cout << "\n\nRemoving " << number<< ":" << endl;
	test.remove(number);
	test.print();
	number = 666;
	cout << "\n\nElement " << number << " found: " << test.find(number) << endl;
	test.print();
	List<int> LNR;
	test.get_data(LNR);

	LNR.print_to_console();
}

