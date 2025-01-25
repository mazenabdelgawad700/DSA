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
int maximumBeauty(vector<int>& nums, int k)
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


int main()
{
	//vector<int> numbers = { 4,6,1,2 }; // 3
	//vector<int> numbers = { 1,1,1,1 }; // 4
	vector<int> numbers = { 75,15,9 }; // 2

	cout << maximumBeauty(numbers, 28) << endl; // 1


	cout << endl;
	system("pause");
	return 0;
}