/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    void traverse(TreeNode* root){
        if(!root) return;        
        if(root->left){
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            traverse(root->left);
        }
        if(root->right){
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            traverse(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        traverse(root);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        while(!q.empty() && k>0){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* curr = q.front();
                // cout<<curr->val<<endl;
                q.pop();
                for(TreeNode* nei: adj[curr]){
                    if(visited.count(nei)) continue;
                    visited.insert(nei);
                    q.push(nei);
                }
            }
            k--;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};