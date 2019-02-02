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
    BSTIterator(TreeNode* root) {
        iterator(root);
    }
    
    void iterator(TreeNode* root)
    {
        if (!root)
            return;

		iterator(root->left);
		pq.push(root->val);
		iterator(root->right);
    }
    /** @return the next smallest number */
    int next() {
        int min = pq.top();
        pq.pop();
        return min;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !pq.empty();
    }

private:
    priority_queue <int, vector<int>, greater<int>> pq;    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
