#include "Stack.h"

#include <iostream>


int main()
{
	Stack<int> myStack;
	int temp = 0;

	while (!myStack.IsEmpty())
	{
		myStack.Pop(temp);
		std::cout << temp << '\t';
	}

	std::cout << "\nHit the any key." << std::endl;
	std::cin.get();

	return 0;
}