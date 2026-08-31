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
    TreeNode* small;
    TreeNode* big;

    void traverse(TreeNode* root, TreeNode*& prev){
        if(!root) return;
        traverse(root->left, prev);
        if(prev!=nullptr){
            // cout<<prev->val<<" "<<root->val<<endl;
            if(root->val<prev->val){
                if(small==nullptr) small = prev;
                big = root;
                // cout<<"small:"<<small->val<<" "<<"big:"<<big->val<<endl;
            }
        }
        prev = root;
        traverse(root->right, prev);
    }
    void recoverTree(TreeNode* root) {        
        small = nullptr;
        big = nullptr;
        TreeNode* prev = nullptr;
        traverse(root, prev);
        // cout<<small->val<<" "<<big->val<<endl;
        swap(small->val, big->val);
        return;
    }
};