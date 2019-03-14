struct Node 
{
	int val;
	Node* left;
	Node* right;
};

namespace Recursive 
{
	/* O(N^2) (worst case), because # of levels in a binary tree could be equal to 
	 * number of nodes for skewed trees */
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
}

namespace Iterative 
{
	/* O(N), with extra space 
	 * it requires space proportional to the maximum number of nodes at given depth */
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
}

namespace UsingHashMap 
{
	void preorder(Node* root, int level, auto& map)
	{
		if (!root)
			return;

		map[level].emplace_back(root->val);

		// recursively traverse its left subtree by increasing level by 1 
		preorder(root->left, level+1, map);
		preorder(root->right, level+1, map);
	}
	// solve the problem in preorder fashion
	void levelOrderTraversal (Node* root)
	{
		if (!root)
			return;

		map <int, vector<int>> map;


		for (const auto & it : map)
		{
			cout << "Level " << it.first << ": ";
			for (const int i : it.second)
				cout << i  << " ";
			cout << endl;
		}
	}

}

