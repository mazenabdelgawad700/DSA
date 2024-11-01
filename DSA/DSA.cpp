#include <iostream>
#include <string>
#include <queue>
#include <cassert>
using namespace std;

class BinaryTree {
private:
	struct Node {
		int item = 0;
		Node* leftPtr = nullptr;
		Node* rightPtr = nullptr;
	};
	Node* root;
	bool isEmpty() {
		return root == nullptr;
	}
	void preorder(Node* node)
	{
		if (isEmpty())
			return;
		if (node != nullptr)
		{
			cout << node->item << " ";
			preorder(node->leftPtr);
			preorder(node->rightPtr);
		}
	}
	void inorder(Node* node)
	{
		if (isEmpty())
			return;
		if (node != nullptr)
		{
			preorder(node->leftPtr);
			cout << node->item << " ";
			preorder(node->rightPtr);
		}
	}
	void postorder(Node* node)
	{
		if (isEmpty())
			return;
		if (node != nullptr)
		{
			preorder(node->leftPtr);
			preorder(node->rightPtr);
			cout << node->item << " ";
		}
	}
	void levelorder(Node* node)
	{
		if (isEmpty())
			return;
		queue<Node*> elements;
		elements.push(node);
		while (!elements.empty())
		{
			Node* current = elements.front();
			cout << current->item << " ";
			if (current->leftPtr != nullptr)
				elements.push(current->leftPtr);
			if (current->rightPtr != nullptr)
				elements.push(current->rightPtr);
			elements.pop();
		}
	}
	bool search_node(Node* node, int itemToSearch) 
	{
		if (node == nullptr)
		{
			cout << "Tree is empty" << endl;
			return false;
		}

		else if (node->item == itemToSearch)
			return true;

		if (itemToSearch < root->item)
			search_node(node->leftPtr, itemToSearch);
		else 
			search_node(node->rightPtr, itemToSearch);

	}
	void deleteFromTree(Node* &node)
	{
		Node* current;   
		Node* trailCurrent;   
		Node* temp;        

		if (node->leftPtr == nullptr && node->rightPtr == nullptr)
		{
			delete node;
			node = nullptr;
		}
		else if (node->leftPtr == nullptr)
		{
			temp = node;
			node = node->rightPtr;
			delete temp;
		}
		else if (node->rightPtr == nullptr)
		{
			temp = node;
			node = node->leftPtr;
			delete temp;
		}
		else
		{
			current = node->leftPtr;
			trailCurrent = nullptr;

			while (current->rightPtr != nullptr)
			{
				trailCurrent = current;
				current = current->rightPtr;
			}

			node->item = current->item;

			if (trailCurrent == nullptr)
				node->leftPtr = current->leftPtr;
			else
				trailCurrent->rightPtr = current->leftPtr;
			delete current;
		}
	}
	int height(Node* node) 
	{
		if (isEmpty())
		{
			cout << "Tree is empty" << endl;
			return 0;
		}

		return max(height(node->leftPtr), height(node->rightPtr));
	}
	int max(int x, int y)
	{
		if (x >= y)
			return x;
		else
			return y;
	}
	int nodeCount(Node* node)
	{
		if (isEmpty())
		{
			cout << "Tree is Empty" << endl;
			return 0;
		}
		return 1 + nodeCount(node->leftPtr) + nodeCount(node->rightPtr);
	}
	int leavesCount(Node* node)
	{
		if (isEmpty())
		{
			cout << "Tree is empty" << endl;
			return 0;
		}

		else if (node->leftPtr == nullptr && node->rightPtr == nullptr)
			return 1;
		else
			return leavesCount(node->leftPtr) + leavesCount(node->rightPtr);
	}
	void clearTree(Node*& node) {
		if (node != nullptr)
		{
			clearTree(node->leftPtr);
			clearTree(node->rightPtr);
			delete node;
			node = nullptr;
		}
	}
	
public:
	BinaryTree() :root(nullptr) {}
	void preorderTraversal()
	{
		preorder(root);
		cout << endl;
	}
	void inorderTraversal()
	{
		inorder(root);
		cout << endl;
	}
	void postorderTraversal()
	{
		postorder(root);
		cout << endl;
	}
	void levelorderTraversal()
	{
		levelorder(root);
	}
	void insert(int itemToInsert) {
		Node* current = new Node();  
		Node* trailCurrent = new Node(); 
		Node* newNode = new Node(); 

		newNode = new Node;
		assert(newNode != nullptr);
		newNode->item = itemToInsert;
		newNode->leftPtr = nullptr;
		newNode->rightPtr = nullptr;

		if (root == nullptr)
			root = newNode;
		else
		{
			current = root;

			while (current != nullptr)
			{
				trailCurrent = current;
				if (current->item > itemToInsert)
					current = current->leftPtr;
				else
					current = current->rightPtr;
			}

			if (trailCurrent->item > itemToInsert)
				trailCurrent->leftPtr = newNode;
			else
				trailCurrent->rightPtr = newNode;
		}
	}
	bool search(int itemToSearch)
	{
		return search_node(root, itemToSearch);
	}
	void remove(int item)
	{
		Node* current;  
		Node* trailCurrent; 

		if (root == nullptr)
		{
			cout << "Tree is Empty" << endl;
			return;
		}
		if (root->item == item)
		{
			deleteFromTree(root);
			return;
		}

		trailCurrent = root;

		if (root->item > item)
			current = root->leftPtr;
		else
			current = root->rightPtr;

		while (current != nullptr)
		{
			if (current->item == item)
				break;
			else
			{
				trailCurrent = current;
				if (current->item > item)
					current = current->leftPtr;
				else
					current = current->rightPtr;
			}
		}

		if (current == nullptr)
			cout << "The delete item is not in the tree." << endl;
		else if (trailCurrent->item > item)
			deleteFromTree(trailCurrent->leftPtr);
		else
			deleteFromTree(trailCurrent->rightPtr);
	}
	void clear()
	{
		clearTree(root);
	}
	int heightOfTree()
	{
		return height(root);
	}
	int maxOfTree(int x, int y)
	{
		return max(x, y);
	}
	int nodeCountOfTree()
	{
		return nodeCount(root);
	}
	int leavesCountOfTree()
	{
		return leavesCount(root);
	}

};

void static BinaryTreeExample()
{
	BinaryTree* BT = new BinaryTree();

	BT->insert(40);
	BT->insert(45);
	BT->insert(30);
	BT->insert(35);
	BT->insert(30);
	BT->insert(22);
	BT->insert(50);

	BT->postorderTraversal();
	
	BT->clear();

	BT->postorderTraversal();

	cout << (BT->search(22) ? "True" : "False");

}

void static heapfiy(int arr[], int n, int i)
{
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;
	int max = i;
	if (left < n && arr[left] > arr[max])
		max = left;
	if (right < n && arr[right] > arr[max])
		max = right;
	
	if (max != i)
	{
		swap(arr[i], arr[max]);
		heapfiy(arr, n, max);
	}
}
void static buildHeap(int arr[], int n)
{
	for(int i = n / 2 - 1; i >= 0; i--)
		heapfiy(arr, n, i);
}
void static heapSort(int arr[], int n)
{
	buildHeap(arr, n);
	for (int i = n - 1; i >=0; i--)
	{
		swap(arr[0], arr[i]);
		heapfiy(arr, n ,0);
	}
}


void static heapSortExample()
{
	int arr[] = { 3, 2, 5, 6, 9, 7, 1 };
	
	for (int i : arr) cout << i << " ";
	
	cout << endl;
	heapSort(arr, 7);
	
	for (int i : arr) cout << i << " ";
}

int main()
{
	//BinaryTreeExample();

	heapSortExample();
	
	cout << endl;
	system("pause");
	return 0;
}