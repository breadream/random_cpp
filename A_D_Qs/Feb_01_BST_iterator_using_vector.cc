/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) : index(0)
    {
        buildList(root);
    }
    void buildList (TreeNode* root)
    {
        if (!root)
            return;
        buildList(root->left);
        nodeList.push_back(root->val); // in-order traversal
        buildList(root->right);
    }
    /** @return the next smallest number */
    int next() 
    {
        return nodeList[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return index < nodeList.size();
    }

private:
    vector<int> nodeList;
    int index;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
