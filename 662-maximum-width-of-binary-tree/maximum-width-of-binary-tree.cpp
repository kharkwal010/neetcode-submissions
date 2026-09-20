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
       deque<pair<TreeNode*, long long>> dq;
       dq.push_back({root, 1});
       long long ans = 0;
       while(!dq.empty()){
        long long st = dq.front().second;
        long long end = dq.back().second;
        ans = max(ans, end - st + 1);
        int sz = dq.size();
        for(int i=0; i<sz; i++){
            TreeNode* curr = dq.front().first;
            long long j = dq.front().second - st;
            dq.pop_front();
            if(curr->left) dq.push_back({curr->left, 2*j});
            if(curr->right) dq.push_back({curr->right, 2*j+1});
        }
       }
       return ans;

    }
};