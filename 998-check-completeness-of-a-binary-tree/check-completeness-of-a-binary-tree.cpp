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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool leave = true;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* curr = q.front();
                q.pop();
                cout<<curr->val<<endl;
                if(!curr->left){
                    leave = false;                
                }
                else{
                    if(!leave) return false;
                    q.push(curr->left);
                }
                if(!curr->right){
                    leave = false;               
                }
                else{
                    if(!leave) return false;
                    q.push(curr->right);
                }                                
            }
        }
        return true;
    }
};