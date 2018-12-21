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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if (!root) return ans;
        traverse(ans, root, 0);
        return ans;
    }
    
    void traverse(vector<vector<int>>& ans, TreeNode* node, int level)
    {
        // create new vector if needed 
        if (ans.size() <= level) ans.push_back({node->val});
        else if (level & 1) // odd number level
            ans[level].insert(ans[level].begin(), node->val);
        else    // even level
            ans[level].emplace_back(node->val);
        
        if (node->left)
            traverse(ans, node->left, level+1);
        if (node->right)
            traverse(ans, node->right, level+1);
    }
};
