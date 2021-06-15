template<class T>
struct ItemType {
	T info;
	ItemType* next;
};

template<class T>
class Queue{
public:
	
	// Sets	qFront and qRear to nullptr
	Queue() : size(0) { qFront = qRear = nullptr; };
	~Queue();

	void MakeEmpty();

	void Enqueue(T);
	void Dequeue(T&);
	void Peek(T&);
	bool IsFull() const;
	bool IsEmpty() const;
	
	unsigned Size() const;

private:
	unsigned int size;

	ItemType<T>* qFront;
	ItemType<T>* qRear;

};

template<class T>
Queue<T>::~Queue()
{
	Queue::MakeEmpty();
}

// Initilize the queue to an empty state.
// Pre: None.
// Post: Queue is empty.
template<class T>
void Queue<T>::MakeEmpty()
{
	ItemType<T>* tempPtr;	

	while (qFront != qRear) {
		tempPtr = qFront;
		qFront = qFront->next;
		delete tempPtr;
	}
	qRear = nullptr;
	size = 0;
}

// Peek
template<class T>
void Queue<T>::Peek(T& item)
{
	item = qFront->info;
}

// Adds newItem to the queue at the back of the queue.
// Pre: Queue has been initilized and is not full.
// Post: newItem has been added to the rear of the queue.
template<class T>
void Queue<T>::Enqueue(T newItem) {
	ItemType<T>* newNode;

	newNode = new ItemType<T>;
	newNode->info = newItem;
	newNode->next = nullptr;

	if (qRear == nullptr)
		qFront = newNode;
	else
		qRear->next = newNode;
	qRear = newNode;
	size++;
}

// Removes an item from the queue at the front of the queue.
// Pre: Queue has been initilized and has an item.
// Post: item has been removed from the rear of the queue.
template <class T>
void Queue<T>::Dequeue(T& item) {
	ItemType<T>* tempPtr;

	tempPtr = qFront;
	item = qFront->info;
	qFront = qFront->next;
	if (qFront == nullptr)
		qRear = nullptr;
	delete tempPtr;
	size--;
}

// Determines whether the queue is empty.
// Pre: Queue has been initlized
// Post: Function value = (Queue is empty)
template<class T>
bool Queue<T>::IsEmpty() const {
	return (qFront == nullptr);
}

// Determines wheter the queue is full.
// Pre: Queue has been initilized.
// Post: Function value = (Queue is full)
template<class T>
bool Queue<T>::IsFull() const{
	ItemType<T>* ptr;

	ptr = new ItemType<T>;
	if (ptr == nullptr) {
		delete ptr;
		return true;
	}else{
		delete ptr;
		return false;
	}
}

// Returns number of object container holds.
// Pre: Queue has been initilized.
// Post: Function value = (size)
template<class T>
unsigned Queue<T>::Size() const {
	return size;
}