struct Node
{
	int val;
	Node* left;
	Node* right; 
	Node(int data) : val(data), left(nullptr), right(nullptr){}
}

void pushTreeNode(Node* root, vector<Node*> &nodes)
{
	if (!root)
		return;

	pushTreeNode(root->left, nodes);
	nodes.emplace_back(root);
	pushTreeNode(root->right, nodes);
}


Node* buildBalancedBST(vector<Node*> &nodes, int start, int end)
{
	if (start > end)
		return nullptr;

	int mid = (start + end) / 2;

	Node* root  = nodes[mid];
	root->left  = buildbalancedbst(nodes, start, mid-1);
	root->right = buildbalancedbst(nodes, mid+1, end  );

	// return root node
	return root;
}

// reference to pointer-to-node (read from right to left)
// *& is used so that we can pass nullptr at the beginning 
void constructBalancedBST(Node* &root)
{
	vector<Node*> nodes;
	pushTreeNode(root, nodes);
	root = buildBalancedBST(node, 0, nodes.size()-1);
}



