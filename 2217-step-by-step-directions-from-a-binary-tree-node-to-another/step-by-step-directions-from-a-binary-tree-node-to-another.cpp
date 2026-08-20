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
    void direction(TreeNode* root, int value, string& comb, string& ans){
        if(root->val==value){
            ans = comb;
            return;
        }
        if(root->left){
            comb.push_back('L');
            direction(root->left, value, comb, ans);
            comb.pop_back();
        }
        if(root->right){
            comb.push_back('R');
            direction(root->right, value, comb, ans);
            comb.pop_back();
        }
    }

    TreeNode* lca(TreeNode* root, int p, int q){
        if(!root || root->val==p || root->val==q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if(left && right) return root;
        return (left) ? left : right;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* ances = lca(root, startValue, destValue);
        string up;
        string down;
        string ans;
        string comb;
        direction(root, startValue, comb, up);
        comb = "";
        direction(root, destValue, comb, down);
        comb = "";
        direction(root, ances->val, comb, ans);
        
        int j = ans.size();
        int len = up.size();
        string res(len-j, 'U');
        for(int i=j; i<down.size(); i++){
            res.push_back(down[i]);
        }
        return res;
    }
};