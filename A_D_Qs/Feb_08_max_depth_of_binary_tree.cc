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
    int maxDepth(TreeNode* root) 
    {
        return !root ? 0 : dfs (root, 0);
    }
    
    int dfs (TreeNode* root, int depth)
    {
        int left = 0, right = 0;
        if (!root) 
            return depth;
        else
        {
            depth++;
            left = dfs (root->left, depth);
            right = dfs (root->right, depth);
        }
        return max(left, right);
    }
};
