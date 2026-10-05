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
    int sum = 0;
    void add(TreeNode* root, int val){
        if(!root) return;
        int curr = val*10 + root->val;
        if(!root->left && !root->right){
            sum += curr;
        }
        add(root->left, curr);
        add(root->right, curr);
    }
    int sumNumbers(TreeNode* root) {
        add(root, 0);
        return sum;
    }
};