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
    pair<int, int> helper(TreeNode* root){
        if(!root) return {0,0};
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        int with = root->val + left.second + right.second;
        int without = max(left.first, left.second) + max(right.first, right.second);
        return {with, without}; 
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = helper(root);
        return max(ans.first, ans.second);
    }
};