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
       if(!root) return 0;
       int left = balance(root->left, check);
       int right = balance(root->right, check);
       if(abs(left-right)>1) check = false;
       return 1+max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        balance(root, ans);
        return ans;
        
    }
};
