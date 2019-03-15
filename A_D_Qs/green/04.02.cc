#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(nullptr), right(nullptr){}
 };

void preOrder(Node* node)
{
	if (!node)
		return;

	stack<Node*> stack; 
	stack.push(node);

	Node* curr = nullptr;
	while (!stack.empty())
	{
		curr = stack.top();
		stack.pop();

		cout << curr->data << " ";

		if (curr->right)
			stack.push(curr->right);

		if (curr->left)
			stack.push(curr->left);
	}
}

Node* createMinimalBST(const vector<int>& arr, int low, int high)
{
	if (low > high)
		return nullptr;

	int mid = low + (high - low) / 2;
	Node* root  = new Node(arr[mid]);
	root->left  = createMinimalBST(arr, low, mid-1);
	root->right = createMinimalBST(arr, mid+1, high);

	return root;
}

Node *createMinimalBST(const vector<int>& arr)
{
	if (arr.empty())
		return nullptr;
	return createMinimalBST(arr, 0, (int)arr.size()-1);
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};

    vector<int> arr (A, A + sizeof(A) / sizeof(A[0]) );
    /*
        Convert List to BST {1,2,3,4,5,6,7}
                         4
                      /     \
                    2         6
                  /   \     /   \
                 1     3   5     7
    */
    Node *root = createMinimalBST(arr);
    cout<<"\nPreOrder Traversal of constructed BST : ";
    preOrder(root);

    return 0;
}
