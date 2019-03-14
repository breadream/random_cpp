/* basic idea
 * (L) - Recursively traverse its left subtree
 * (N) - Process N itself
 * (R) - Recursively traverse its right subtree
 */

// Recusive approach

void inOrderTraversal(Node* root)
{
	if (!root)
		return;
	// (L)
	inOrderTraversal(root->left);
	// (N)
	cout << root->val << endl;
	// (R)
	inOrderTraversal(root->right);
}

// Iterative approach
void inOrderTraversal(Node* root)
{
	stack<Node*> stack;
	Node* curr = root;

	while (!stack.empty() || curr != nullptr)
	{
		// iteratively traverse left subtree
		if (curr != nullptr)
		{
			stack.push(curr);
			curr = curr->left;
		}
		else  // print out current node and recursively traverse right subtree
		{
			cout << stack.top()->val << endl;
			stack.pop();
			curr = curr->right;
		}
	}
}


