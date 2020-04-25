// Header file for Stack ADT
template<class T>
struct NodeStack {
	T info;
	NodeStack* next;
};

template <class T>
class Stack
{
public:
	Stack();
	~Stack();

	void MakeEmpty();
	void Push(T);
	void Pop(T&);

	bool IsEmpty() const;
	bool IsFull();

	int Size() const;

private:
	unsigned int size;
	NodeStack<T>* topPtr;

};

template<class T>
Stack<T>::Stack() : size(0) {
	topPtr = nullptr;
}

template<class T>
Stack<T>::~Stack() {
	MakeEmpty();
}

// Emptys out the stack.
// Post: Stack is empty; all items have been removed from the stack.
template<class T>
void Stack<T>::MakeEmpty() {
	
	NodeStack<T>* tempPtr;

	while (topPtr != nullptr)
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
	size = 0;
}

// Adds newItem to the top of the stack.
// Pre: Stack has been initilized and is not full.
// Post: item is at top of stack.
template<class T>
void Stack<T>::Push(T newItem) {
	NodeStack<T>* location;

	location = new NodeStack<T>;
	location->info = newItem;
	location->next = topPtr;
	topPtr = location;
	size++;
}

// Removes item off the top of the stack.
// Pre: Stack is not empty and holds an item.
// Post: item has been removed from top of stack.
template<class T>
void Stack<T>::Pop(T& item) {
	NodeStack<T>* tempPtr;

	item = topPtr->info;
	tempPtr = topPtr;
	topPtr = topPtr->next;
	
	size--;
	delete tempPtr;
}

template<class T>
bool Stack<T>::IsEmpty() const{
	return (topPtr == nullptr);
}

template<class T>
bool Stack<T>::IsFull() {
	NodeStack<T>* location;

	location = new NodeStack<T>;
	if (location == nullptr)
		return true;
	else
	{
		delete location;
		return false;
	}
}

template<class T>
int Stack<T>::Size() const {
	return size;
}