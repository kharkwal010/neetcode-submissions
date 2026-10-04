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
    bool dir(TreeNode* root, int value, string& ans){
        if(!root) return false;
        if(root->val==value) return true;
        bool left = dir(root->left, value, ans);
        if(left){
            ans.push_back('L');
            return true;
        }
        else{
            bool right = dir(root->right, value, ans);
            if(right){
                ans.push_back('R');
                return true;
            }
        }
        return false;
    }

    TreeNode* anscestor(TreeNode* root, int st, int end){
        if(!root || root->val==st || root->val==end) return root;
        TreeNode* left = anscestor(root->left, st, end);
        TreeNode* right = anscestor(root->right, st, end);
        if(left && right) return root;
        return (left) ? left : right;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
      string one = "";
      string two = "";
      TreeNode* ances = anscestor(root, startValue, destValue);
      dir(ances, startValue, one);
      dir(ances, destValue, two);
      int n = one.size();
      reverse(two.begin(), two.end());
      string first = string(n,'U');
      return first + two;
    }
};