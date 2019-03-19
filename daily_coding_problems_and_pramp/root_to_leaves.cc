Node 
{
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(nullptr), right(nullptr);
}


vector<vector<int>> rootToLeaf (Node* root)
{
	vector<vector<int>> res;

	if (!root)
		return res;
	traverse(root, res, "");

	return res;
}

void traverse(Node* root, vector<vector<int>> res, vector<int> temp)
{
	if(root == nullptr)
		return;

	temp.push_back(root->data);
	if (!root->left && !root->right)
	{
		res.push_back(temp);
	}
	else 
	{
		traverse(root->left, res, temp);
		traverse(root->right, res, temp);
	}
}
