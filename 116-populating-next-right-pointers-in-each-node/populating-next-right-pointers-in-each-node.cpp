/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            Node* prev = q.front();
            if(prev->left){
                q.push(prev->left);
                q.push(prev->right);
            }
            q.pop();
            
            for(int i=1; i<sz; i++){
                Node* curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    q.push(curr->right);
                }
                prev->next = curr;
                prev = curr;
            }
            prev->next = nullptr;            

        }
        return root;
    }
};