template<class T>
struct QueueType {
	T info;
	QueueType* next;
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
	bool IsFull() const;
	bool IsEmpty() const;
	
	unsigned Size() const;

private:
	unsigned int size;

	QueueType<T>* qFront;
	QueueType<T>* qRear;

};

template<class T>
Queue<T>::~Queue()
{
	Queue::MakeEmpty();
}

// Post: queue is empty and all items removed.
template<class T>
void Queue<T>::MakeEmpty()
{
	QueueType<T>* tempPtr;

	while (qFront != qRear) {
		tempPtr = qFront;
		qFront = qFront->next;
		delete tempPtr;
	}
	qRear = nullptr;
	size = 0;
}

// Adds newItem to the queue at the back of the queue.
// Pre: Queue has been initilized and is not full.
// Post: newItem has been added to the rear of the queue.
template<class T>
void Queue<T>::Enqueue(T newItem) {
	QueueType<T>* newNode;

	newNode = new QueueType<T>;
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
	QueueType<T>* tempPtr;

	tempPtr = qFront;
	item = qFront->info;
	qFront = qFront->next;
	if (qFront == nullptr)
		qRear = nullptr;
	delete tempPtr;
	size--;
}

// Returns true if there are elements in the queue; otherwise returns false.
template<class T>
bool Queue<T>::IsEmpty() const {
	return (qFront == nullptr);
}

template<class T>
bool Queue<T>::IsFull() const{
	QueueType<T>* ptr;

	ptr = new QueueType<T>;
	if (ptr == nullptr) {
		delete ptr;
		return true;
	}else{
		delete ptr;
		return false;
	}
}

template<class T>
unsigned Queue<T>::Size() const {
	return size;
}