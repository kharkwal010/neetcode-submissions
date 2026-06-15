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
    unordered_map<Node*, Node*> visited;
    void dfs(Node* copy, Node* node){
        for(Node* n: node->neighbors){
            if(visited.find(n)==visited.end()){
                Node* c = new Node(n->val);
                visited[n]=c;
                copy->neighbors.push_back(visited[n]);
                dfs(visited[n], n);
            }
            else copy->neighbors.push_back(visited[n]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        Node* copy = new Node(node->val);
        visited[node]=copy;
        dfs(copy, node);
        return copy;
    }
};
