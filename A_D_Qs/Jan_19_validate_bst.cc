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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
private:
    bool isValidBST(TreeNode* root, long min, long max)
    {
        if (!root)
            return true;
        if (root->val <= min || max <= root->val)
            return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};
