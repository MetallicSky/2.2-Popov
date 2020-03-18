#include "pch.h"
#include "RBTree.h"
#include <iostream>
#include <Windows.h>


using namespace std;


int main()
{
	RBTree<int> test;
	for (int i = 0; i < 10; i++)
	{
		int number = rand() % 100;
		cout << "\n\n step " << number << "\n\n";
		test.insert(number);
		test.Print();
	}

}

