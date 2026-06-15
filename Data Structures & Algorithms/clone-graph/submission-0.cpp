/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mapped;
    Node* dfs(Node* node){
        if(node==nullptr) return nullptr;
        if(mapped.count(node)) return mapped[node];
        Node* copy = new Node(node->val);
        mapped[node]=copy;
        for(auto nei: node->neighbors){
            copy->neighbors.push_back(dfs(nei));
        }
        return copy;
    }
    

    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        return dfs(node);      
        
    }
};
