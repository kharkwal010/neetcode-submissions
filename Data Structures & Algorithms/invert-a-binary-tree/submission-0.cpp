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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* top = root;
        if (root==nullptr){
            return nullptr;
        }
         stack<TreeNode*> stack;
         stack.push(root);
         while(!stack.empty()){
            TreeNode* node= stack.top();
            swap(node->left, node->right);
            stack.pop();
            if (node->right){
            stack.push(node->right);
            }
            if (node->left){
            stack.push(node->left);
            }
         }
         return top;
    }
};
