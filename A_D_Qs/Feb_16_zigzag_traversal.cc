/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        traverse(ans, root, 0);
        return ans;    
    }
    
    void traverse (vector<vector<int>>& ans, TreeNode* root, int level)
    {
        // first element at this tree depth level. Create a new vector with its value and put into the result
        if (ans.size() <= level) 
            ans.push_back({root->val});
        else
        {
            if (level & 1) // odd number
                ans[level].insert(ans[level].begin(), root->val); // insert number from front 
            else // even number
                ans[level].emplace_back(root->val);   
        }
        
        if (root->left)    
            traverse(ans, root->left, level+1);
        if (root->right) 
            traverse(ans, root->right, level+1);
    }
};
