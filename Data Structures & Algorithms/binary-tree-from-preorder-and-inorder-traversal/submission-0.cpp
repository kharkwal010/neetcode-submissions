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
    unordered_map<int, int> index;
    int pindex = 0;
    TreeNode* tree(vector<int> preorder, int l, int r){
        if(l>r) return nullptr;
        int value = preorder[pindex];
        pindex++;
        TreeNode* root = new TreeNode(value);
        int mid = index[value];
        root->left = tree(preorder, l, mid-1);
        root->right = tree(preorder, mid+1, r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            index[inorder[i]]=i;            
        }
        return tree(preorder, 0, inorder.size()-1);
    }
};
