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
    int p = 0;
    unordered_map<int, int> pos;
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder, int l, int r){
        if(l>r) return nullptr;
        TreeNode* root = new TreeNode(preorder[p]);
        int term = pos[preorder[p]];
        p++;
        root->left = tree(preorder, inorder, l, term-1);
        root->right = tree(preorder, inorder, term+1, r);
        return root;      

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            pos[inorder[i]] = i;
        }
        return tree(preorder, inorder, 0, inorder.size()-1);
    }
};
