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


 /*
 this will have 3 states:
    me having : 1
    child of one having : 0;
    parent of one having : 2
    overall needed (min(left, right) + 1)%3;
 */
class Solution {
public:
    int count;
    int camera(TreeNode* root){
        if(!root) return 2;
        int left = camera(root->left);
        int right = camera(root->right);
        int curr = (min(left, right) + 1) % 3;
        if(curr==1) count++;
        return curr;
    }
    int minCameraCover(TreeNode* root) {
        count = 0;
        int val = camera(root);
        if(val==0) count++;        
        return count;

    }
};