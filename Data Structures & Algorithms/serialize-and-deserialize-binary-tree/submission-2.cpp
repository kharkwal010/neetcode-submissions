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

    void traverse(TreeNode* root, string& ans){
        if(!root){
            ans += "n,";
            return;
        }
        ans += to_string(root->val) + ",";
        traverse(root->left, ans);
        traverse(root->right, ans);
    
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        traverse(root, ans);
        return ans;
    }
    TreeNode* cons(vector<string> nodes, int& i){
        if(nodes[i]=="n"){
            i++;
            return nullptr;
        }
        int val = stoi(nodes[i]);
        i++;
        TreeNode* root = new TreeNode(val);
        root->left = cons(nodes, i);
        root->right = cons(nodes, i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        stringstream ss(data);
        string terms;
        while(getline(ss, terms, ',')){
            nodes.push_back(terms);
        }
        int i=0;
        return cons(nodes, i);
    }
};
