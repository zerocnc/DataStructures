#include "Stack.h"
#include "Queues.h"

#include <iostream>


int main()
{
	Queue<int> myQueue;
	int x;

	myQueue.Enqueue(3);
	myQueue.Enqueue(4);
	myQueue.Enqueue(5);
	myQueue.Enqueue(1);
	myQueue.Enqueue(9);

	std::cout << "Size of queue is: " << myQueue.Size() << std::endl;

	while (!myQueue.IsEmpty())
	{
		myQueue.Dequeue(x);
		std::cout << x << '\t';
	}

	std::cout << "\nHit the any key." << std::endl;
	std::cin.get();

	return 0;
}