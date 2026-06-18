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
    unordered_map<int, int> ind;
    int pos;
    TreeNode* tree(vector<int>& postorder, int l, int r){
        if(l>r) return nullptr;
        TreeNode* nde = new TreeNode(postorder[pos]);
        int p = ind[postorder[pos]];
        pos--;
        nde->right = tree(postorder, p+1, r);
        nde->left = tree(postorder, l, p-1);
        return nde;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++){
            ind[inorder[i]] = i;
        }
        pos = postorder.size() - 1;
        return tree(postorder, 0, pos);
        

    }
};