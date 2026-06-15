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

class Solution {
public:
    unordered_map<int, int> pos;
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder, int& i, int l, int r){
        if(l>r) return nullptr;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        int p = pos[root->val];
        root->left = tree(preorder, inorder, i, l, p-1);
        root->right = tree(preorder, inorder, i, p+1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            pos[inorder[i]]=i;
        }
        int i = 0;
        return tree(preorder, inorder, i, 0, inorder.size()-1);
        
    }
};
