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

void levelOrderTraversal(Node* root)
{
	if (!root)
		return;

	int level = 1;

	while (printEachLevel(root, level))
		level++;
}
