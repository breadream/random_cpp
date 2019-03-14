struct Node 
{
	int val;
	Node* left;
	Node* right;
};

bool printEachLevel(Node* root, int level)
{
	if (!root)
		return false;

	if (level == 1)
	{
		cout << root->val << endl;
		return true;
	}

	// go down to their subtree as much as 'level'
	bool left  = printEachLevel(root->left, level-1);
	bool right = printEachLevel(root->right, level-1);
	
	return left || right;
}

bool printEachLevel (Node* root)
{
	if (!root)
		return false;

	Node* curr = nullptr;
	queue<Node*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		curr = queue.front();	
		pop_front();

		cout << curr->val << out;

		if (curr->val)
			queue.push(curr->left);

		if (curr->right)
			queue.push(curr->right);
	}
}

void levelOrderTraversal(Node* root)
{
	if (!root)
		return;

	int level = 1;

	while (printEachLevel(root, level))
		level++;
}
