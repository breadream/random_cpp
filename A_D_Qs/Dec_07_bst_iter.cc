**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root != nullptr)
        {
            stack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = stack.top();
        int smallest = top->val;
        stack.pop();
        if (top->right != nullptr)
        {
            top = top->right;
            while (top != nullptr)
            {
                stack.push(top);
                top = top->left;
            }
        }
        return smallest;
    }
        
private:
    std::stack <TreeNode*> stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
