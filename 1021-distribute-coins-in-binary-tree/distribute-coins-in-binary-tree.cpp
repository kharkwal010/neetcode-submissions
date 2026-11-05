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
    int value(TreeNode* root){
        if(!root) return 0;
        root->val = root->val + value(root->right) + value(root->left);
        int send = root->val - 1;
        // cout<<send<<endl;
        ans += abs(send);
        return send;
    }
    int distributeCoins(TreeNode* root) {
        ans = 0;
        value(root);
        return ans;
    }
};