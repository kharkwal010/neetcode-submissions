/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    TreeNode* tree(vector<string> nodes, int& i){
        if(nodes[i]=="N") return nullptr;
        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;
        root->left = tree(nodes, i);
        i++;
        root->right = tree(nodes, i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string nd;
        stringstream ss(data);
        while(getline(ss, nd, ',')){
            nodes.push_back(nd);
        }
        int i=0;
        return tree(nodes, i);        
    }
};
