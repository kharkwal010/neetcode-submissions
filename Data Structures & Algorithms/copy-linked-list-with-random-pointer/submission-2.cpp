/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      unordered_map<Node*, Node*> match;
      Node* curr = head;
      while(curr){
        Node* node = new Node(curr->val);
        match[curr] = node;
        curr = curr->next;
      }
      Node* ans = match[head];
      curr = head;
      while(curr){
        if(curr->next) match[curr]->next = match[curr->next];
        if(curr->random) match[curr]->random = match[curr->random];
        curr = curr->next;
      }
      return ans;
        
    }
};
