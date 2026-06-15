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
        unordered_map<Node*, Node*> mapped;
        if(head==nullptr) return nullptr;
        Node* copy = new Node(head->val);
        Node* h = head;
        Node* ans = copy;
        mapped[head]=copy;
        while(head->next){
            head = head->next;
            Node* next = new Node(head->val);
            copy->next = next;
            copy = next;
            mapped[head]=copy;
        }
        while(h){
            mapped[h]->random= mapped[h->random];
            h=h->next;
        }     
        return ans;  
        
    }
};
