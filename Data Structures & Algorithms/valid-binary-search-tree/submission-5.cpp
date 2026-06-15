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
    void valid(TreeNode* root, int left, int right, bool& check){
        if(!root){
            return;
        }
        if(!(left<root->val && right>root->val)){
            check=false;
        }
        valid (root->left, left, root->val, check);
        valid (root->right, root->val, right, check);
    }

    bool isValidBST(TreeNode* root) {
       bool check = true;
       valid(root,-1001,1001, check);
       return check;
        
    }
};
