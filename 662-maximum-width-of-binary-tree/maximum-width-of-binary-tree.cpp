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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long width = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});     // root, val
        while(!q.empty()){
            int n = q.size();
            long long st = q.front().second;
            for(int i=0; i<n; i++){
                auto[curr, val] = q.front();
                q.pop();
                width = max(width, val - st + 1);
                val -= st;
                // cout<<val - st + 1<<endl;
                if(curr->left) q.push({curr->left, val*2});
                if(curr->right) q.push({curr->right, val*2+1});
            }
        }
        return width;
    }
};