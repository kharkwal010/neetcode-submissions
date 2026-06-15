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
    bool check(TreeNode* root, TreeNode* p){
        if(!root){
            return false;
        }
        if(root==p){
            return true;
        }
        return check(root->left, p) || check(root->right, p);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool one = check(root, p);
        bool two = check(root, q);
        if(!(one && two)){
            return nullptr;
        }

        TreeNode* res;
        res = root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        if (left){
            return left;
        }
        TreeNode* right =  lowestCommonAncestor(root->right, p, q);
        if(right){
            return right;
        }
        
        return res;
    }
};
