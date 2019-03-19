#include <iostream>

using namespace std;

struct Node 
{
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(nullptr), right(nullptr) {} 
};

int sizeTree(Node* root)
{
	if (!root)
		return 0;

	return sizeTree(root->left) + 1 + sizeTree(root->right);
}

bool isBST(Node* root, int min, int max)
{
	if (!root)
		return true;

	if (root->data < min || root->data > max)
		return false;

	return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

int findLargestBST(Node* node)
{
	if (isBST(node, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()))
		return sizeTree(node);

	return max(sizeTree(node->left), sizeTree(node->right));
}

// main function
int main()
{
	/* Construct below binary tree

			  10
			/	\
		   /	  \
		  15	   8
		 / \	  / \
		/   \	/   \
	   12   20  5	 2
	*/

	Node* root = new Node(10);

	root->left = new Node(15);
	root->right = new Node(8);

	root->left->left = new Node(12);
	root->left->right = new Node(20);

	root->right->left = new Node(5);
	root->right->right = new Node(2);

	cout << "The size of the largest BST is " << findLargestBST(root);

	return 0;
}
