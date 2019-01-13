/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if (!root)
            return "#"; // make a mark to represent nullptr
        else
            return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        return deserialize_helper(data);
    }
    
    TreeNode* deserialize_helper(string &data)
    {
        // if the first character is the marker for nullptr
        if (data[0] == '#')
        {
            if (data.length() > 1)
                data = data.substr(2); // skip the current character and following ','
            return nullptr; // add null
        }
        else // otherwise construct a new tree node 
        {
            TreeNode* root = new TreeNode(getValue(data));
            root->left  = deserialize_helper(data);
            root->right = deserialize_helper(data);
            return root;
        }
    }

private:
    int getValue (string& data) 
    {
        // find the position of ',' = the length of value 
        int pos = data.find(',');
        int val = stoi(data.substr(0, pos)); // get the value starting from index 0 until the value's end position
        // new data is assigned as the string after ',' to the end 
        data = data.substr(pos+1);
        return val;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
