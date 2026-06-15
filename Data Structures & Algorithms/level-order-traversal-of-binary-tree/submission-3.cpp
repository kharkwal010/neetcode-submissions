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
    void dfs(TreeNode* root, vector<vector<int>>& res, int depth){
        if (!root){return;}
        if (depth >=res.size()){
            res.resize(depth+1);
        }
        res[depth].push_back(root->val);
        dfs(root->left, res, depth+1);
        dfs(root->right, res, depth+1);
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> res;
      dfs(root, res, 0);
      return res;  
    }
};
