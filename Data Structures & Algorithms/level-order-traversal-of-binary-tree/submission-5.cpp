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
        queue<TreeNode*> queue;
        if(!root){
            return ans;
        }
        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            vector<int> layer;
            for(int i=0; i<size; i++){
                auto node = queue.front();
                queue.pop();
                layer.push_back(node->val);
                if(node->left){
                    queue.push(node->left);
                }
                if(node->right){
                    queue.push(node->right);
                }
            }
            ans.push_back(layer);
        }
        return ans;
    }
};
