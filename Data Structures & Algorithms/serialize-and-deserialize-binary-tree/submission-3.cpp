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
        if(!root) return "n,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* tree(vector<string>nodes, int& i){
        if(nodes[i]=="n"){
            i++;
            return nullptr;
        }
        int value = stoi(nodes[i]);
        i++;
        TreeNode* root = new TreeNode(value);
        root->left = tree(nodes, i);
        root->right = tree(nodes, i);
        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string comp;
        vector<string> nodes;
        while(getline(ss, comp, ',')){
            nodes.push_back(comp);
        }
        int i=0;
        return tree(nodes, i);
    }
};
