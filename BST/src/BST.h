#include <ostream>

/*********************************************************************
*
*  Binary Search Tree: A structure with a unique starting node (the 
*  root), in which each node is capable of having two child nodes, and 
*  in which a unique path exists from the root to every other node in 
*  the tree.
*
**********************************************************************/

// Assumption: T is a type for which the operators "<" and "==" are defined
// either in an appropriate built-in type or a class that overloads these
// operators
template<class T>
struct NodeTree{
	T info;
	NodeTree* left;
	NodeTree* right;

	NodeTree() {
		left = nullptr;
		right = nullptr;
	}
};

/*********************************************************************
*
*  Structure: The placement of each element in the binary tree must
*       satisify the binary search property : the value of the key of 
*       the element is greater than the value of the element of its left-
*       subtree, and less than any value of the element of its right-subtree
*
**********************************************************************/

enum OrderType{ PRE_ORDER, IN_ORDER , POST_ORDER};

template<class T>
class TreeType{
public:
	TreeType();
	~TreeType();

	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull();

	int NumberOfNodes() const;

	void RetrieveItem(T&, bool&);
	void InsertItem(T);
	void DeleteItem(T);
	void PrintTree(std::ostream&);
	void ResetTree(OrderType);
	void GetNextItem(T&, OrderType, bool&);

	// Copy Constructor
	void operator=(const TreeType<T>& OriginalTree);
	TreeType(const TreeType<T>& OriginalTree);

private:
	NodeTree<T>* root;

};

template<class T>
TreeType<T>::TreeType(){
	root = nullptr;
}

template<class T>
TreeType<T>::~TreeType() {

}

// Returns the number of nodes counted; helper function
template<class T>
int CountNodes(TreeType<T>* tree) {

	if (tree == nullptr)
		return 0;
	else
		return CountNodes(tree->left) + CountNodest(tree->right) + 1;
}

//   Definition: Counts the Number of nodes in the tree
//         Size: Number of nodes in the tree
//    Base Case: If tree is nullptr, return 0
// General Case:Return CountNodes(Left(Tree)) + CountNodes(Right(tree)) + 1
template<class T>
int TreeType<T>::NumberOfNodes() const {
	return CountNodes(root);
}



