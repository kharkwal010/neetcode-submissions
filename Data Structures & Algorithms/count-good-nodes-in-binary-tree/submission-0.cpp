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
    void dfs(TreeNode* root, int max, int& count){
        if(!root){
            return;
        }
        if (root->val>=max){
            max = root->val;
            count++;
        }
        dfs(root->left, max, count);
        dfs(root->right, max, count);

    }
    int goodNodes(TreeNode* root) {
        int count=0;
        int max = root->val;
        dfs(root, max, count);
        return count;
    }
};
