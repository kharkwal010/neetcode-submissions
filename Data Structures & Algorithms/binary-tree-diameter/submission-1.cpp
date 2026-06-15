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
    int depth(TreeNode* root, int& res){
        if(!root){
            return 0;
        }
        res = max(res, depth(root->left, res)+depth(root->right, res));
        return 1+max(+depth(root->left, res),depth(root->right, res));
    }

    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
       depth(root, res);
       return res;

    }
};
