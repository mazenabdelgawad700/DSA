#include <cassert>
#include <iostream>
#include <queue>
#include<set>
#include <string>
#include<unordered_map>
#include<unordered_set>
#include <utility> 
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
	void deleteFromTree(Node*& node)
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
	for (int i = n / 2 - 1; i >= 0; i--)
		heapfiy(arr, n, i);
}
void static heapSort(int arr[], int n)
{
	buildHeap(arr, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapfiy(arr, n, 0);
	}
}
void static print(int arr[], int size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
}
void static heapSortExample()
{
	int arr[] = { 3, 2, 5, 6, 9, 7, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	print(arr, size);

	cout << endl;
	heapSort(arr, size);

	print(arr, size);

}
int static maxProfit(vector<int>& prices) {
	int left = 0, right = 1, current = 0, maxProft = 0;

	while (right < prices.size())
	{
		if (prices.at(left) < prices.at(right))
		{
			current = prices.at(right) - prices.at(left);
			maxProft = max(maxProft, current);
		}
		else
			left = right;
		right++;
	}
	return maxProft;
}
int static lengthOfLongestSubstring(string s) {
	unordered_set<char> charSet;
	int l = 0, res = 0;

	for (int r = 0; r < s.length(); ++r) {
		while (charSet.find(s[r]) != charSet.end())
		{
			charSet.erase(s[l]);
			++l;
		}
		charSet.insert(s[r]);
		res = max(res, r - l + 1);
	}
	return res;
}
vector<int> static get_k_sum(vector<int>& numbers, int k)
{
	vector<int> result;
	int p1 = 0, p2 = numbers.size() - 1, sum = 0;
	while (p1 < p2)
	{
		sum = numbers.at(p1) + numbers.at(p2);
		if (sum == k)
		{
			result.push_back(numbers.at(p1));
			result.push_back(numbers.at(p2));
			return result;
		}
		else if (sum < k)
			p1++;
		else
			p2--;
	}
}
void static draw_pyramid(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j >= i; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void static draw_triangle(int number_of_starts)
{
	for (int i = 1; i <= 4; i++)
	{
		for (int space = 1; space <= 4 + i; space++)
		{
			cout << " ";
		}

		for (int i = 1; i <= number_of_starts; i++)
		{
			cout << "*";
		}
		number_of_starts -= 2;
		cout << endl;
	}
}
int static remove_duplicates(vector<int>& nums) {
	int l = 0, r = 1;
	while (r < nums.size())
	{
		if (nums.at(r) != nums.at(l))
		{
			l++;
			nums.at(l) = nums.at(r);
		}
		else
			r++;
	}
	return ++l;
}
void static print_vector(vector<int> numbers)
{
	for (int n : numbers)
		cout << n << " ";
	cout << endl;
}
vector<int> static twoSum(vector<int>& numbers, int target) {
	vector<int> result;
	int l = 0, r = numbers.size() - 1;
	while (r < numbers.size())
	{
		if (numbers.at(l) + numbers.at(r) > target)
			r--;
		else if (numbers.at(l) + numbers.at(r) < target)
			l++;
		else
		{
			result.push_back(++l);
			result.push_back(++r);
			return result;
		}
	}
	return result;
}
void static reverse_array(vector<int>& nums, int begin, int end)
{
	while (begin < end)
	{
		int temp = nums.at(begin);
		nums.at(begin) = nums.at(end);
		nums.at(end) = temp;
		begin++;
		end--;
	}
}
void static rotate(vector<int>& nums, int k)
{
	if (nums.size() >= k)
	{
		reverse_array(nums, 0, nums.size() - 1);
		reverse_array(nums, 0, k - 1);
		reverse_array(nums, k, nums.size() - 1);
	}
}
int static max_area(vector<int>& height) {
	int left = 0, right = height.size() - 1, max_area = 0;
	while (left < right)
	{
		int width = right - left;
		int current_height = min(height.at(left), height.at(right));
		int current_area = width * current_height;

		max_area = max(current_area, max_area);

		if (height.at(left) < height.at(right))
			left++;
		else
			right--;
	}
	return max_area;
}
vector<int> static productExceptSelf(vector<int>& nums) {
	int n = nums.size();
	vector<int> result(n, 1);

	int prefix = 1;
	for (int i = 0; i < n; i++) {
		result.at(i) = prefix;
		prefix *= nums.at(i);
	}

	int suffix = 1;
	for (int i = n - 1; i >= 0; i--) {
		result.at(i) *= suffix;
		suffix *= nums.at(i);
	}

	return result;
}
long long static continuousSubarrays(vector<int>& nums) {
	long long num = 0LL;
	int left = 0, right = left, low = nums[left] - 2, high = nums[left] + 2, n = nums.size();

	while (right < n)
	{
		if (nums[right] <= high && nums[right] >= low)
		{
			num += right - left + 1;
			high = min(high, nums[right] + 2);
			low = max(low, nums[right] - 2);
			++right;
		}
		else
		{
			int i = right - 1;
			high = nums[right] + 2;
			low = nums[right] - 2;
			while (abs(nums[i] - nums[right]) <= 2)
			{
				high = min(high, nums[i] + 2);
				low = max(low, nums[i] - 2);
				--i;
			}
			left = i + 1;
		}
	}
	return num;
}
long long static continuousSubarrays2(vector<int>& nums) {
	long long count = 0; int l = 0, r = 0;
	int current_min = nums[0], current_max = nums[0];
	while (r < nums.size())
	{
		current_min = min(current_min, nums[r]);
		current_max = max(current_max, nums[r]);
		while (abs(current_max - current_min) > 2)
		{
			l += 1;
			current_min = nums[l];
			current_max = nums[l];
			for (int i = l; i <= r; i++)
			{
				current_min = min(current_min, nums[i]);
				current_max = max(current_max, nums[i]);
			}
		}
		count += (r - l) + 1;
		r += 1;
	}
	return count;
}
long long static findScore2(vector<int>& nums) {
	long long score = 0; int size = nums.size();
	vector<bool> marked(size, false);
	while (true)
	{

		for (int i = 0; i < size; i++)
		{
			if (marked[i])
			{
				if (i == size - 1)
				{
					return score;
				}
				else
					continue;
			}
			else
				break;
		}


		int l = 0, r = size - 1;



		while (l != r)
		{
			if (nums[l] <= nums[r])
			{
				if (marked[l])
				{
					l++;
				}
				else
				{
					r--;
				}
			}
			else
			{
				if (marked[r])
				{
					r--;
				}
				else
				{
					l++;
				}
			}
		}
		score += nums[l];

		marked[l] = true;

		if (l > 0)
			marked[l - 1] = true;

		if (l <= size - 2)
			marked.at(l + 1) = true;
	}
	return score;
}
long long static findScore(vector<int>& nums)
{
	int n = nums.size();
	long long score = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

	vector<bool> marked(n, false);

	for (int i = 0; i < n; i++) {
		minHeap.push({ nums[i], i });
	}


	while (!minHeap.empty()) {
		int value = minHeap.top().first;
		int index = minHeap.top().second;

		minHeap.pop();

		if (marked[index]) continue;

		score += value;

		marked[index] = true;
		if (index > 0) marked[index - 1] = true;
		if (index < n - 1) marked[index + 1] = true;
	}

	return score;
}
int static maximumBeauty(vector<int>& nums, int k)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < nums.size(); i++)
		minHeap.push(nums[i]);

	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] = minHeap.top();
		minHeap.pop();
	}
	int l = 0, r = nums.size() - 1, count = 0;
	while (l <= r)
	{
		if (nums[r] - nums[l] <= 2 * k)
		{
			r--;
			count++;
		}
		else
			l++;
	}
	return count;
}
class BinarySearchTree
{
	struct Node
	{
		int val;
		Node* right;
		Node* left;
	};
private:
	Node* root;
	long count_value = 0;
	void insert(Node*& root, int val)
	{
		if (root == nullptr)
		{
			root = new Node();
			count_value++;
			root->val = val;
		}
		else
		{
			if (val > root->val)
			{
				insert(root->right, val);
			}
			else
			{
				insert(root->left, val);
			}
		}
	}
	void preorder(Node* node)
	{
		if (isEmpty())
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (node != nullptr)
		{
			cout << node->val << " ";
			preorder(node->left);
			preorder(node->right);
		}
	}
	void inorder(Node* node)
	{
		if (isEmpty())
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (node != nullptr)
		{
			preorder(node->left);
			cout << node->val << " ";
			preorder(node->right);
		}
	}
	bool search(Node* root, int val)
	{
		if (root == nullptr)
			return false;

		while (root != nullptr)
		{
			if (root->val == val)
				return true;
			else if (val > root->val)
			{
				root = root->right;
				search(root, val);
			}
			else
			{
				root = root->left;
				search(root, val);
			}
		}
	}
	Node* find_min(Node* root)
	{
		while (root->left != nullptr)
			root = root->left;
		return root;
	}
	Node* delete_node(Node*& root, int val) {
		if (root == nullptr)
			return root;

		if (val < root->val)
		{
			root->left = delete_node(root->left, val);
		}
		else if (val > root->val)
		{
			root->right = delete_node(root->right, val);
		}
		else
		{
			if (root->left == nullptr && root->right == nullptr)
			{
				delete root;
				root = nullptr;
				return nullptr;
			}
			if (root->left == nullptr)
			{
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr)
			{
				Node* temp = root->left;
				delete root;
				return temp;
			}

			Node* successor = find_min(root->right);
			root->val = successor->val;
			root->right = delete_node(root->right, successor->val);
		}

		return root;
	}

public:
	BinarySearchTree()
	{
		root = nullptr;
	}
	void insert(int val)
	{
		insert(root, val);
	}
	void preorder()
	{
		preorder(root);
	}
	void inorder()
	{
		inorder(root);
	}
	bool isEmpty()
	{
		return root == nullptr;
	}
	bool search(int value_to_search)
	{
		return search(root, value_to_search);
	}
	long count()
	{
		return count_value;
	}
	void delete_node(int val)
	{
		delete_node(root, val);
	}
};
void static binary_search_tree_exmpale()
{
	BinarySearchTree* bst = new BinarySearchTree();

	bst->insert(4);
	bst->insert(3);
	bst->insert(5);
	bst->insert(6);
	bst->insert(7);
	bst->insert(8);
	bst->insert(12);

	bst->inorder(); // 3 4 5 6 7 8 12
	bst->delete_node(6);
	cout << "\nAfter deletion" << endl;
	bst->inorder(); // 3 4 5 7 8 12
}
/*AVL Tree */
struct Node
{
	Node* left;
	Node* right;
	int value, freq, height;
	static Node* sentinel; // One Null for all tree elements
	Node()
	{
		memset(this, 0, sizeof * this); // Initialize all memeber variables to zero
	}
	Node(int val)
	{
		value = val;
		freq = height = 1;
		left = right = sentinel;
	}
	void update_height()
	{
		height = 1 + max(left->height, right->height);
	}
	int balance_factor()
	{
		return left->height - right->height;
	}
};
Node* Node::sentinel = new Node();
Node* right_rotation(Node* Q)
{
	Node* P = Q->left;
	Q->left = P->right;
	P->right = Q;
	Q->update_height();
	P->update_height();

	return P;
}
Node* left_rotation(Node* P)
{
	Node* Q = P->right;
	P->right = Q->left;
	Q->left = P;
	Q->update_height();
	P->update_height();

	return Q;
}
Node* balance(Node* root)
{
	if (root->balance_factor() == 2)
	{
		if (root->left->balance_factor() == -1)
			root->left = left_rotation(root->left);
		root = right_rotation(root);
	}
	else if (root->balance_factor() == -2)
	{
		if (root->right->balance_factor() == 1)
			root->right = right_rotation(root->right);
		root = left_rotation(root);
	}
	return root;
}
Node* insert(Node*& root, int val)
{
	// Normal BST
	if (root == Node::sentinel)
		return new Node(val);

	if (val == root->value)
	{
		root->freq++;
		return root;
	}

	else if (val > root->value)
		root->right = insert(root->right, val);

	else
		root->left = insert(root->left, val);

	// AVL Change
	root->update_height();
	root = balance(root);
	return root;
}
void inorder_traversal(Node* root) {
	if (root == Node::sentinel)
		return;

	inorder_traversal(root->left);
	cout << root->value << " ";
	inorder_traversal(root->right);
}
bool search(Node* root, int val)
{
	if (root == Node::sentinel)
		return false;

	while (root != Node::sentinel)
	{
		if (root->value == val)
			return true;
		else if (val > root->value)
		{
			root = root->right;
			search(root, val);
		}
		else
		{
			root = root->left;
			search(root, val);
		}
	}
}
void AVL_tree_exmpale()
{
	Node* root = Node::sentinel;

	root = insert(root, 3);
	root = insert(root, 5);
	root = insert(root, 9);
	root = insert(root, 1);
	root = insert(root, 0);
	root = insert(root, 2);
	root = insert(root, 6);
	root = insert(root, 10);
	root = insert(root, 7);
	root = insert(root, 4);
	root = insert(root, 8);

	//inorder_traversal(root);
	int value_to_search = 7;
	string result = search(root, value_to_search) ? " is exist" : " is not exist";
	cout << value_to_search << result << endl;
}
// @TODO:: Delete Element
/*AVL Tree */


int main()
{
	AVL_tree_exmpale();

	cout << endl; system("pause");
}