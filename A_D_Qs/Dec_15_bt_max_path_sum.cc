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
int curr_max_sum;    
public:
    int maxPathSum(TreeNode* root) 
    {
        curr_max_sum = numeric_limits<int>::min();
        getMax(root);
        return curr_max_sum;
    }
    int getMax(TreeNode* root)
    {
        if (!root)
            return 0;
        int l = max(0, getMax(root->left)); // find the max in left node's tree 
        int r = max(0, getMax(root->right)); // find the max in right node's tree
        curr_max_sum = max(curr_max_sum, l + r + root->val);
        return max(l, r) + root->val; // choose one of node's sum plus its value 
    }
};
