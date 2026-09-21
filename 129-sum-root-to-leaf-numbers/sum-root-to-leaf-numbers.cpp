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
    vector<string> terms(TreeNode* root){
        if(!root->left && !root->right) return {to_string(root->val)};
        vector<string> left;
        vector<string> right;
        if(root->left) left = terms(root->left);
        if(root->right) right = terms(root->right);
        char c = root->val + '0';
        vector<string> ans;
        for(auto& ele: left){
            string temp = ele;
            temp.push_back(c);
            ans.push_back(temp);
        }
        for(auto& ele: right){
            string temp = ele;
            temp.push_back(c);
            ans.push_back(temp);
        }
        return ans;
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<string> curr = terms(root);
        int ans = 0;
        for(string& s: curr){
            reverse(s.begin(), s.end());
            ans += stoi(s);
        }
        return ans;
    }
};