/*
 * (L) Recursively traverse left subtree, when this step is done we are back at N 
 * (R) Recursively traverse right subtree, when this step is done we are back at N 
 * (N) Process N itself 
 * */

void postOrderTraversal(Node* root)
{
	if (!root)
		return;

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->val << endl;
}

// Iterative approach

void postOrderTraversal(Node* root)
{
	stack<Node*> stack;
	stack.push(root);
	stack<int> output; // stack to contain post-order traversal

	
	Node* curr = nullptr;
	while(!stack.empty())
	{
		curr = stack.top();
		stack.pop();

		output.push(curr->val);

		if (curr->left) // left first because output stack is FIFO
			stack.push(curr->left);
		if (curr->right)
			stack.push(curr->right);
	}

	while (!output.empty())
	{
		cout << output->top() << " ";
		output.pop();
	}
}
