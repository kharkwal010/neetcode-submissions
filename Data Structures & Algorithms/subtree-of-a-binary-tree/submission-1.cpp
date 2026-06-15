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
    bool check(TreeNode* one, TreeNode* second){
        if(!one && !second){
            return true;
        } 
        if (!one || !second) return false;
        if (one->val!=second->val){
            return false;
        }
        
        return check (one->left, second->left) && check (one->right, second->right);
     
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        if (root->val==subRoot->val){
            bool what= check(root, subRoot);
            if (what==true){
                return true;
            }
        }
       
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
      
       
    }
    
};
