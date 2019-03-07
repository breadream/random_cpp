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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val == q->val)
            return p;
        
        vector<TreeNode*> pPath, qPath;
        if (!findPath(root, pPath, p) || !findPath(root, qPath, q))
            return nullptr;
       
        int i;
        for (i = 0; i < pPath.size() && i < qPath.size(); i++)
            if (pPath[i]->val != qPath[i]->val)
                break;
        
        return pPath[i-1];
    }
    
    bool findPath(TreeNode* root, vector<TreeNode*>& path, TreeNode* k)
    {
        if (root == nullptr)
            return false;
        
        path.emplace_back(root);
        if (root->val == k->val)
            return true;
        
        if ((root->left && findPath(root->left, path, k)) 
            || (root->right && findPath(root->right, path, k)))
            return true;
        
        // if not present in subtree rooted with root, remove root from path
        path.pop_back();
        return false;
    }
};
