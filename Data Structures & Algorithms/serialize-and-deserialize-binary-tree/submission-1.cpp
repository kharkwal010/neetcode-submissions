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
        return to_string(root->val)+"," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* tree(vector<string> s, int& i){
        if(s[i]=="n"){
            i++;
            return nullptr;                        
        } 
        TreeNode* root = new TreeNode(stoi(s[i]));
        i++;
        root->left = tree(s, i);
        root->right = tree(s, i);
        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<string> terms;
        string s;
        while(getline(ss, s, ',')){
            terms.push_back(s);
        }
        int i=0;
        return tree(terms, i);
        
    }
};
