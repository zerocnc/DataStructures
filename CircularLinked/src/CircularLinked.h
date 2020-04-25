#include <inttypes.h>

template<class T>
struct NodeCircle {
	T info;
	NodeCircle* next;
};

template<class T>
class CircleType {
public:

	CircleType(); // Class Constructor
	~CircleType(); // Class Deconstructor

	bool IsFull() const;

	uint32_t LenghtIs() const;

	void MakeEmpty();

	/*

	void RetrieveItem(T& item, bool& found);

	void InsertItem(T item);

	void DeleteItem(T item);

	void ResetUnsortedList();

	void GetNextItem(T& item);

	bool IsEmpty(); */

private:
	uint32_t length;

	NodeCircle<T>* circleData;
	NodeCircle<T>* predLoc;
	NodeCircle<T>* location

};

template <class T>
CircleType<T>::CircleType()
{
	uint32_t = 0;
	circleData = nullptr;
	predLoc = nullptr;
	location = nullptr;
}

template <class T>
CircleType<T>::~CircleType()
{
	MakeEmpty();
}

template <class T>
void CircleType<T>::MakeEmpty() {

}

template <class T>
bool CircleType<T>::IsFull() const {
	NodeCircle<T>* ptr;
	ptr = new NodeCircle<T>;

	if (ptr == nullptr) {
		delete ptr;
		return true;
	}
	else {
		delete ptr;
		return false;
	}
}

template <class T>
uint32_t CircleType<T>::LenghtIs() const {
	return length;
}