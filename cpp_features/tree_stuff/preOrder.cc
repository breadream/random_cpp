/* Basic idea 
 * (N) Process N itself
 * (L) Recursively traverse its left subtree. When this step is finished we are back at N again
 * (R) Recursively traverse its right subtree. When this step is finished we are back at N again
 * */

void preOrder (Node* root)
{
	if (!root)
		return;
	// (N)
	cout << root->data << endl;
	// (L)
	preOrder(root->left);
	// (R)
	preOrder(root->right);
}


// iterative implementation (stack based)
void preOrder (Node* root)
{
	if (!root)
		return;

	stack<Node*> stack;
	stack.push(root);

	Node* curr = nullptr;
	while (!stack.empty())
	{
		curr = stack.top();
		stack.pop();

		// (N)
		cout << curr->val << endl;

		/* (R) goes first as stack pops in FIFO manner */
		if (curr->right)
			stack.push(curr->right);

		// (L)
		if (curr->left)
			stack.push(curr->left);
	}
}

