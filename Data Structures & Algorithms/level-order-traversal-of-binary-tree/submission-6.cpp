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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root){
            q.push(root);  
        }
        while(!q.empty()){
            int size = q.size();
            vector<int> layer;
            for(int i=0; i<size; i++){
                auto term = q.front();
                q.pop();
                layer.push_back(term->val);
                if(term->left){
                    q.push(term->left);
                }
                if(term->right){
                    q.push(term->right);
                }
            }
            ans.push_back(layer);
        }
        return ans;

    }
};
