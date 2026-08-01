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
    pair<int, int> heights(TreeNode* root){
        int lh = 1;
        TreeNode* curr = root;
        while(curr->left){
            lh++;
            curr = curr->left;
        }
        curr = root;
        int rh = 1;
        while(curr->right){
            rh++;
            curr = curr->right;
        }
        return {lh, rh};
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        auto terms = heights(root);
        if(terms.first==terms.second) return (1<<terms.first) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};