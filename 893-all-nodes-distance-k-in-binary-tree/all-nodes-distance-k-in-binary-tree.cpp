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
        }
        if(root->right){
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
        }
        
        traverse(root->left);
        traverse(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        traverse(root);
        visited.insert(target);
        q.push(target);
        // cout<<adj[target].size()<<endl;
        while(k>0){
            int sz = q.size();
            if(sz==0) break;
            for(int i=0; i<sz; i++){
                TreeNode* curr = q.front();
                q.pop();
                for(auto e: adj[curr]){
                    if(visited.count(e)) continue;
                    visited.insert(e);
                    q.push(e);
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