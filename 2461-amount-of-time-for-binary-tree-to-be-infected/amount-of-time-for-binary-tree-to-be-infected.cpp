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
    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    TreeNode* curr;
    void build(TreeNode* root, int& start){
        if(root->val==start) curr = root;
        if(root->left){
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            build(root->left, start);
        }
        if(root->right){
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            build(root->right, start);
        }
        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        build(root, start);
        int count = 0;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({curr, nullptr});
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto top = q.front();
                q.pop();
                TreeNode* nde = top.first;
                for(TreeNode* nei: adj[nde]){
                    if(nei==top.second) continue;
                    q.push({nei, nde});
                }
            }
            count++;
        }
        return count-1;
    }
};