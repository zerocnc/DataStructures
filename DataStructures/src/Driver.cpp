#include "Stack.h"
#include "Queues.h"
#include "ListADT.h"
#include "CircularLinked.h"
#include "BST.h"

#include <iostream>


int main()
{
	TreeType<int> myTree;

	myTree.InsertItem(6);
	myTree.InsertItem(2);
	myTree.InsertItem(4);
	myTree.InsertItem(8);
	myTree.InsertItem(6);
	myTree.InsertItem(10);
	

	std::cout << "\nHit the any key." << std::endl;
	std::cin.get();

	return 0;
}