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
       Node* original = head;
       while(original){
        Node* curr = new Node(original->val);
        match[original] = curr;
        original = original->next;
       }
       Node* ans = match[head];
       while(head){
        match[head]->next = match[head->next];
        match[head]->random=match[head->random];
        head = head->next;
       }
       return ans;
        
    }
};
