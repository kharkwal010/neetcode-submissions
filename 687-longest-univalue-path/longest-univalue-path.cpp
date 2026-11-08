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
    int ans;
    int path(TreeNode* root){
        if(!root) return 0;
        int left = path(root->left);
        int right = path(root->right);
        int l = 0;
        int r = 0;
        if(root->left && root->val == root->left->val) l = max(l, left);
        if(root->right && root->val== root->right->val) r = max(r, right);
        ans = max(ans,  l + r);
        return 1 + max(l, r);
    }
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        path(root);
        return ans;
    }
};