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
    int ans;
    vector<int> camera(TreeNode* root){
        if(!root) return {1,0,0};
        vector<int> left = camera(root->left);
        vector<int> right = camera(root->right);
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(left[i]==1) maxi = max(maxi, i);
            if(right[i]==1) maxi = max(maxi, i);
        }
        int next = (3+maxi-1)%3;
        if(next==1) ans++;
        vector<int> nxt(3,0);
        nxt[next] = 1;
        return nxt;
    }
    int minCameraCover(TreeNode* root) {
        ans = 0;
        vector<int> val= camera(root);
        if(val[2]==1) ans++;
        return ans;

    }
};