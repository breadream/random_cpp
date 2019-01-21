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
    bool isValidBST(TreeNode* root) 
    {
        return isValidBST(root, nullptr, nullptr);
    }
private:    
    // min node -> has lower limit , max node -> has upper limit
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) 
    {
        // if it reaches the end node, return true
        if (!root)  
            return true;
        // check the value whether it is in range between min and max 
        if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        
        // check whether left subtree is BST or not (upper limit = current)
        // check whether right subtree is BST or not (lower limit = current) 
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};
