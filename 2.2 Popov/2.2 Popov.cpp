#include "pch.h"
#include "RBTree.h"
#include "Map.h"
#include "List.h"
#include <iostream>
#include <Windows.h>
#include <exception>
#include <string>


using namespace std;


int main()
{
	Map<string, int> test;
	/*for (int i = 0; i < 10; i++)
	{
		int number0 = rand() % 100;
		char number1 = rand() % 100;
		cout << "\n\n step " << number0 << " - " << number1 << "\n\n";
		test.insert(number0, number1);
		test.printTree();
		test.printList();
	}*/
	
	test.insert("Jan", 24);
	test.printList();
	cout << "\n\n";
	cout << "\n\n";
	test.insert("Feb", 34);
	test.printList();
	cout << "\n\n";
	test.insert("Mar", 24);
	test.printList();
	cout << "\n\n";
	test.insert("Apr", 34);
	test.printList();
	test.printTree();
	cout << "\n\n";
	string key= "Apr";
	cout << "\n\nRemoving " << key << ":" << endl;
	test.remove(key);
	test.printList();
	test.printTree();
	key = "Feb";
	cout << "\n\nElement " << key << " has value: " << test.find(key) << endl;
	test.printList();
	
	List<int> vls;
	test.get_values(vls);
	cout << "\n\n";
	vls.print_to_console();

	List<string> kys;
	test.get_keys(kys);
	cout << "\n\n";
	kys.print_to_console();
}

