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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        if(p && !q || !p && q){
            return false;
        }
            stack<TreeNode*> one;
            stack<TreeNode*> two;
            one.push(p);
            two.push(q);
            while(!(one.empty() && two.empty())){
                if(one.empty() && !(two.empty())){
                    return false;
                }
                 if(two.empty() && !(one.empty())){
                    return false;
                }
                TreeNode* val1= one.top();
                TreeNode* val2= two.top();
                one.pop();
                two.pop();
                int num1= val1->val;
                int num2= val2->val;

                if (num1!=num2){
                    return false;
                }
                if (val1->left){
                    if(!(val2->left)){
                       return false; 
                    }
                    else{
                        one.push(val1->left);
                        two.push(val2->left);
                    }
                }
                if (!(val1->left)){
                    if((val2->left)){
                       return false; 
                    }
                }
                if (val1->right){
                    if(!(val2->right)){
                       return false; 
                    }
                    else{
                        one.push(val1->right);
                        two.push(val2->right);
                    }
                }
                 if (!(val1->right)){
                    if((val2->right)){
                       return false; 
                    }
                }
            }
            return true;
    }
};
