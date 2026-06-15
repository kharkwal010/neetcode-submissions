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
    int balance(TreeNode* root, bool& res){
        if(!root) return 0;
        int left = balance(root->left, res);
        int right = balance(root->right, res);
        if(abs(left-right)>1){
            res = false;
        }
        return 1+max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        bool res = true;
        balance(root, res);
        return res;
    }
};
