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
	void PrintTree(std::ofstream&) const;
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

// Calls recursive function to deallocate the tree.
template<class T>
TreeType<T>::~TreeType() {
	Destory(root);
}

template<class T>
void Destory(NodeTree<T>*& tree) {
	if (tree != nullptr) {
		Destory(tree->left);
		Destory(tree->right);
		delete tree;

		// tree = nullptr; // MSN may needs this!
	}
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

//   Definition: Searches for an element with the same key as item's key. If found, store it into item.
//         Size: Number of nodes in the tree (or number of nodes in the path)
//    Base Case: (1) If item's key matches key Info(tree), item is set to Info(tree) and found is true.
//               (2) If tree = NULL, found is false.
// General Case: If item's key is less than key in Info(tree), Retrieve(Left(tree), item, found); else 
//               Retrieve(Right(tree), item, found).

// Calls recursive function Retrieve to search the tree for item.
template<class T>
void TreeType<T>::RetrieveItem(T& item, bool& found) {
	Retrieve(root, item, found);
}

// Recursively searches tree for item.
// Posts: If there is an element info who's key matches item's.
//        found is set to true and item is set to a copy of info;
//        otherwise found is false and item is unchanged.
template<class T>
void Retrieve(NodeTree<T>* tree, T& item, bool& found ) {
	if (tree == nullptr)
		found = false;	// item is not found.
	else if (item < tree->info)
		Retrieve(tree->left, item, found);  // Search left sub-tree.
	else if (item > tree->info)	
		Retrieve(tree->right, item, found);	// Search right sub-tree.
	else
	{
		item = tree->info;	// item is found.
		found = true;
	}
}


/***************************************************************************************************
*   Definition: Inserts into binary search tree.
*         Size: The number nodes in the path from root to insertion place.
*         Base: If tree is nullptr, then allocate a new leaf node to contain.
* General Case: (1) If item < Info(tree), then Insert(Left(tree), item).
*               (2) If item > Info(tree), then Insert(Right(tree), item).
***************************************************************************************************/
template<class T>
void TreeType<T>::InsertItem(T item) {
	Insert(root, item);
}
// Inserts item into tree.
// Post: item is in the tree; search property is maintained.
template<class T>
void Insert(NodeTree<T>*& tree, T item) {
	if (tree == nullptr)
	{	// Insertion found.
		tree = new NodeTree<T>;
		tree->right = nullptr;
		tree->left = nullptr;
		tree->info = item;
	}
	else if (item < tree->info)
		Insert(tree->left, item); // Insert into left subtree.
	else
		Insert(tree->right, item); // Insert into right subtree.
}

/***************************************************************************************************
*   Definition: Removes item from tree where item equals someItem.
*         Size: The number nodes in the path from root to the node to be deleted.
*         Base: If item's key matches key Info(tree), delete ndoe poitned to by tree.
* General Case: (1) If item < Info(tree), then Delete(Left(tree), item).
*               (2) If item > Info(tree), then Delete(Right(tree), item).
***************************************************************************************************/

// Class Recursive function to Delete item from tree.
template<class T>
void TreeType<T>::DeleteItem(T item) {
	Delete(root, item);
}

// Deletes item from the tree.
template<class T>
void Delete(NodeTree<T>*& tree, T item) {
	if (item < tree->info)
		Delete(tree->left, item);
	else if (item > tree->info)
		Delete(tree->right, item);
	else
		DeleteNode(tree);
}

// Deletes the node pointed to by tree.
// Post: The user's data in teh node pointed to by tree is no longer in the tree. If tree is a leaf node or 
//       has only one non-nullptr child pointer. the node is poitned to by tree is deleted; otherwise, the user's
//       data is replaced by iit's logical predecessor and the predecessor's node is deleted.
template<class T>
void DeleteNode(NodeTree<T>*& tree)
{
	T data;
	NodeTree<T>* tempPtr;

	tempPtr = tree;

	if (tree->left == nullptr) {
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == nullptr)
	{
		tree = tree->left;
		delete tempPtr;
	}
	else
	{
		GetPredecessor(tree, data);
		tree->info = data;
		Delete(tree->left, data); // Delete predecessor node.
	}
}

// Sets the data to the info member of the right-most node in the tree.
template<class T>
void GetPredecessor(NodeTree<T>* tree, T& data) {
	while (tree->right != nullptr) {
		tree = tree->right;
	}

	data = tree->info;
}

// Prints info member of item in tree in sorted order on outFile.
template<class T>
void Print(NodeTree<T>* tree, std::ofstream& outFile) {
	if (tree != nullptr) {
		// Inorder tranversal.
		Print(tree->left, outFile);
		outFile << tree->info;
		Print(tree->right, outFile);
	}
}

template<class T>
void TreeType<T>::PrintTree(std::ofstream& outFile) const {
	Print(root, outFile);
}

/** - Copy Trees - **/

// Calls recursive function CopyTree to copy tree pointed to by originalTree into self.
template<class T>
TreeType<T>::TreeType(const TreeType<T>& originalTree) {
	CopyTree(root, originalTree.root);
}

// Calls recursive function CopyTree to copy tree pointed to by originalTree into self.
template<class T>
void TreeType<T>::operator=(const TreeType<T>& originalTree) {
	if (&originalTree == this)
		return;		// Ignore assigning self to self.
	Destory(root);  // Deallocate existing tree nodes.
	CopyTree(root, originalTree.root);
}

template<class T>
void CopyTree(NodeTree<T>*& copy, const NodeTree<T>* originalTree) {

	if (originalTree == nullptr)
		copy = nullptr;
	else
	{
		copy = new NodeTree<T>;
		copy->info = originalTree->info;
		CopyTree(copy->left, originalTree->left);
		CopyTree(copy->right, originalTree->right);
	}
}