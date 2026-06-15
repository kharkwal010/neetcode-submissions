/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode val(0);
        ListNode* curr  = &val;
        ListNode* returning  = curr;
        int carry = 0;
        while(l1 && l2){
            int val = l1->val + l2->val + carry;           
            curr->next =  new ListNode(val%10);
            curr= curr->next;
            carry = val / 10;
            l1=l1->next;
            l2=l2->next;
        }
        if(l2){
            l1 = l2;
        }
        while(l1){
            int val = l1->val + carry;           
            curr->next =  new ListNode(val%10);
            curr= curr->next;
            carry = val / 10;
            l1=l1->next;
        }
        if(carry!=0){
            curr->next =  new ListNode(carry);
        }
        return returning->next;


        
    }

};
