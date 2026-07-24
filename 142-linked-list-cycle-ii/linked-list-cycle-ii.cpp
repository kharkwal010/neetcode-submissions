/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while(fast){
            if(slow==fast){
                while(head!=slow){
                    head= head->next;
                    slow= slow->next;
                }
                return head;
            }
            slow = slow->next;
            if(!fast->next) break;
            fast = fast->next->next;
        }
        return nullptr;
        
    }
};