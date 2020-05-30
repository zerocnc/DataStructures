// Assumes ItemType is either a built-in simple type or a class with overloaded relationa operators.
template<class ItemType>
struct HeapType {
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	ItemType* elements; // Array to be allocated.
	int numElements;
};

// Swaps the elements given, user-defined class has pre-defined move/copy.
template<class ItemType>
void Swap(ItemType& x, ItemType& y) {
	ItemType z;

	z = x;
	x = y;
	y = z;
}

// Post: Heap property is restored.
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom) {
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom) {
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}

		if (elements[root] < elements[maxChild])
		{
			Swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}

}

// Post: Heap property is restored.
template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom) {
	
	int parent = 0;

	if (bottom > root)
	{
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom]) {
			Swap(elements[parent], elements[bottom]);
			ReheapUp(root, bottom);
		}
	}

	return;
}

/************************************************************************************
 *  Structure: The Priority Queue is arranged to support access to the highest 
 *             priority item.
 *  Assumptions: Before any call is made to a priority queue operation, the queue 
 *               has been declared and a constructor has been applied.
*************************************************************************************/
template<class ItemType>
class PQType {
public:
	PQType(int);
	~PQType();

	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType& item);
private:
	int numItems;
	HeapType<ItemType> items;
	int maxItems;
};

/*********** Operations ***************/
template<class ItemType>
PQType<ItemType>::PQType(int max) {
	maxItems = max;
	items.elements = new ItemType[max]{'\0'};
	numItems = 0;
	items.numElements = 0;
}

// 	Function: Initializes the queue to an empty state.
//  Postconditions: Queue is empty.
template<class ItemType>
void PQType<ItemType>::MakeEmpty() {
	numItems = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType() {
	delete[] items.elements;
}

// 	Function: Removes element with highest priority and returns it in item.
//  Precondition: Queue is not empty.
//  Postcondition : Highest priority element has been removed form queue item is a copy of removed element.
template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item) {
	item = items.elements[0];
	items.elements[0] = items.elements[numItems - 1];
	numItems--;
	items.ReheapDown(0, numItems - 1);
}

// 	Function: Pushes item to rear of queue.
//  Precondition: Queue isn't full.
//  Postcondition : item is in the queue.
template<class ItemType>
void PQType<ItemType>::Enqueue(const ItemType item) {
	// numItems++;
	items.elements[ numItems++ ] = item;
	items.ReheapUp(0, numItems - 1);
}

template<class ItemType>
bool PQType<ItemType>::IsFull() const {
	return numItems == maxItems;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const {
	return numItems == 0;
}