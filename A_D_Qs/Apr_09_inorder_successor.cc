/* If you store parent link, 
 * 1. If the current node has a right child, the leftmost child of the right child is the inorder successor
 *    if the current node has no right child, the right child is the inorder successor 
 * 2. Navigate up the parent ancestor nodes, 
 * 	  and when you find a parent whose left child is the node you're currently at, 
 * 	  the parent is the inorder successor of your original node.
 * 	  */

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	// Case 1 : Right subtree is not empty
	if (p->right)
	{
		TreeNode* curr = p->right;
		// loop down to find the leftmost leaf
		while(curr->left)
			curr = curr->left;

		return curr;
	}

	// Case 2 : Right subtree is empty
	// Start from root and search for successor down the tree
	TreeNode* succ = nullptr;
	while (root)
	{
		if (p->val < root->val)
		{
			succ = root;
			root = root->left;
		}
		else if (p->val > root->val)
			root = root->right;
		else if (p->val == root->val)
			break;
	}
	return succ;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
{
	TreeNode* succ = nullptr;
	while (root)
	{
		if (p->val < root->val)
		{
			succ = root;
			root = root->left;
		}
		else if (p->val >= root->val)
			root = root->right;
	}
	return succ;
}

// recursive approach
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
  if (!root)
    return nullptr;

  if (root->val <= p->val) 
    return successor(root->right, p);
   else 
  {
    TreeNode* left = successor(root->left, p);
	// if left is nullptr, current root node is the inorder successor
    return (left != nullptr) ? left : root; 
  }
}
