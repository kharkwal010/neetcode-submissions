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
 maximum of left, sum , minimum of right, is_binary
 */
class Solution {
public:
    int ans;
    vector<int> binary(TreeNode* root){
        if(!root) return {INT_MIN, INT_MAX, 0, true};           //{maxi, mini, sum, is_bst}
        auto left = binary(root->left);
        auto right = binary(root->right);
        int maxi = root->val;
        int mini = root->val; 
        int lsum = 0;
        int rsum = 0;
        bool one = false;
        bool two = false;
        if(left[3] && left[0]<root->val){
            one = true;
            lsum = left[2];
            mini = min(mini, left[1]);
        }
        if(right[3] && right[1]>root->val){
            two = true;
            rsum = right[2];
            maxi = max(maxi, right[0]);
        }
        if(!(one && two)) return {0, 0, 0, false};
        int curr = root->val + lsum + rsum;
        ans = max(ans, curr);
        return {maxi, mini, curr, true};        
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        binary(root);
        return ans;
    }
};