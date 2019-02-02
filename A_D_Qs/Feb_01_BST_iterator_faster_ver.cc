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
    BSTIterator(TreeNode* root) 
    {
        find_left(root); // start with root for now
    }
    
    void find_left(TreeNode* root)
    {
        TreeNode* curr = root;
        while (curr)
        {
            st.push(curr); // put the all left child of root 
            curr = curr->left;
        }
    }
    /** @return the next smallest number */
    int next() 
    {
        TreeNode* top = st.top(); // top is the smallest number
        st.pop();
        if (top->right)
            find_left(top->right);
        
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !st.empty();
    }

private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
