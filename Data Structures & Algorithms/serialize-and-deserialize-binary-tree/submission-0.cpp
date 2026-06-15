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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(!root) return "";
        else q.push(root);
        ans.push_back(root->val);
        while(!q.empty()){
            queue<TreeNode*> layer;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    layer.push(node->left);
                    ans.push_back(node->left->val);
                }
                else ans.push_back(1001);
                if(node->right){
                    layer.push(node->right);
                    ans.push_back(node->right->val);
                }
                else ans.push_back(1001);
            }
            while(!layer.empty()){
                auto top = layer.front();
                layer.pop();
                q.push(top);
            }
        }
        string code;
        for(int item: ans){
            string term;
            if(item==1001){
                term = "N";
            }
            else term = to_string(item);
            code = code + term + ",";
        }
        code.pop_back();
        return code;
    }

    // Decodes your encoded data to tree.
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        vector<string> value = split(data, ',');
        TreeNode* root = new TreeNode(stoi(value[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(!q.empty()){
            queue<TreeNode*> layer;
            while(!q.empty()){
                TreeNode* curr=q.front();
                q.pop();
                if(value[i]!="N"){
                    curr->left = new TreeNode(stoi(value[i]));
                    layer.push(curr->left);
                }
                i++;
                if(value[i]!="N"){
                    curr->right = new TreeNode(stoi(value[i]));
                    layer.push(curr->right);
                }
                i++;                
            }
            while(!layer.empty()){
                auto top = layer.front();
                layer.pop();
                q.push(top);
            }
        }
        return root;
    
    }
};
