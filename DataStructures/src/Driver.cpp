#include "Stack.h"
#include "Queues.h"
#include "ListADT.h"

#include <iostream>


int main()
{
	UnsortedType<int> myList;

	int x;

	std::cout << "Size of list is: " << myList.LenghtIs() << std::endl;

	myList.InsertItem(1);
	myList.InsertItem(3);
	myList.InsertItem(5);
	myList.InsertItem(7);
	myList.InsertItem(9);

	myList.ResetUnsortedList();

	for (int ndx = 0; ndx < myList.LenghtIs(); ndx++ )
	{
		myList.GetNextItem(x);
		std::cout << x << '\t';
	}

	std::cout << "\nHit the any key." << std::endl;
	std::cin.get();

	return 0;
}