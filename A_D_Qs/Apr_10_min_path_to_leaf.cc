struct TreeNode
{
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(nullptr), right(nullptr) {}
}

// sum, path(vector)
// store the path, sum the path, compare the sum of path 
vector<int> minPathSumToLeaf (TreeNode* root)
{
	vector<int> res;
	vector<int> tempPath;
	traversePath(root, res, tempPath, 0, numeric_limits<int>::max());
	return  
}

void traversePath(TreeNode* node, vector<int>& res, vector<int>& tempPath, int &currSum, int &minSum)
{
	if (!node)
		return nullptr;

	currSum += node->data;
	tempPath.emplace_back(node->data);

	if (node->left == nullptr && node->right == nullptr)
	{
		if (currSum < minSum)
		{
			minSum = currSum;
			res = tempPath;
		}
	}
	traversePath(node->left, res, tempPath, currSum, minSum);
	traversePath(node->left, res, tempPath, currSum, minSum);
}


 


