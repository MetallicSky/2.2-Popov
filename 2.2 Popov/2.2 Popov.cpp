#include "pch.h"
#include "RBTree.h"
#include <iostream>
#include <Windows.h>


using namespace std;


int main()
{
	RBTree<int> test;
	/*for (int i = 0; i < 10; i++)
	{
		int number = rand() % 100;
		cout << "\n\n step " << number << "\n\n";
		test.insert(number);
		test.Print();
	}*/
	test.insert(41);
	test.Print();
	cout << "\n\n";
	test.insert(67);
	test.Print();
	cout << "\n\n";
	test.insert(34);
	test.Print();
	cout << "\n\n";
	test.insert(0);
	test.Print();
	cout << "\n\n";
	test.insert(69);
	test.Print();
	cout << "\n\n";
	test.insert(24);
	test.Print();
	cout << "\n\n";
	test.insert(67);
	test.Print();
	cout << "\n\n";
	test.insert(67);
	test.Print();
	cout << "\n\n";
	test.insert(78);
	test.Print();
	cout << "\n\n";
	test.insert(58);
	test.Print();
	cout << "\n\n";
	test.insert(62);
	test.Print();
	cout << "\n\n";
	test.insert(64);
	test.Print();
	cout << "\n\n";
	int number = 67;
	cout << "\n\nRemoving " << number<< ":" << endl;
	test.remove(number);
	test.Print();
}

