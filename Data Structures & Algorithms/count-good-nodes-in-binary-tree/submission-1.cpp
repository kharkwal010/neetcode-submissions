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
    void good(TreeNode* root, int maxi, int& count){
        if(!root){
            return;
        }
        if(root->val>=maxi){
            count++;
            maxi = root->val;
        }
        good(root->right, maxi, count);
        good(root->left, maxi, count);
    }
    
    int goodNodes(TreeNode* root) {
      int maxi = root->val;
      int count = 0;
      good(root, maxi, count);
      return count;

    }
};
