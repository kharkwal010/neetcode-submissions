/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void check(TreeNode* root, TreeNode* p, TreeNode* q, bool& one, bool& two){
        if(root==p){
            one = true;
        }
        else if(root==q){
            two = true;
        }
        if(one && two) return;
        if(root->left) check(root->left, p, q, one, two);
        if(root->right) check(root->right, p, q, one, two);
    }
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        bool one = false;
        bool two = false;
        if(root->left) check(root->left, p, q, one, two);
        if(one && two) return lca(root->left, p, q);
        one = false;
        two = false;
        if(root->right) check(root->right, p, q, one, two);
        if(one && two) return lca(root->right, p, q);
        return root;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};