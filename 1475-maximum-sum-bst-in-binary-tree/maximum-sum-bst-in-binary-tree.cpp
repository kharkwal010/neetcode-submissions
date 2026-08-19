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
        if(!root) return {INT_MIN, 0, INT_MAX, 1};
        vector<int> left = binary(root->left);
        vector<int> right = binary(root->right);
        int bin = 1;
        int sum = 0;
        if(left[3]==1 && right[3]==1){
            if(left[0]<root->val && right[2]>root->val){
                sum = root->val + left[1] + right[1];
                ans = max(ans, sum);
                int left_max = max({root->val, left[0], right[0]});
                int right_min = min({root->val, left[2], right[2]});
                return {left_max, sum, right_min, 1};
            }
        }
        return {INT_MAX, 0, INT_MIN, 0};
        
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        binary(root);
        return ans;
    }
};