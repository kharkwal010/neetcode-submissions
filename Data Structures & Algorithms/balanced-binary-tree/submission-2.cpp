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
    int balance(TreeNode* root, bool& check){
        if(!root){
            return 0;
        }
        if(abs(balance(root->right, check)-balance(root->left, check))>1){
            check=false;
        }
        return 1+ max(balance(root->right, check), balance(root->left, check));
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        balance(root, ans);
        return ans;
        
    }
};
