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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid =  slow;
        ListNode* curr = mid->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;
        
        while(curr){
            ListNode* temp = curr->next;
            curr->next =  prev;
            prev = curr;
            curr = temp;
            
        }
        ListNode* first = head;
        ListNode* second = prev;
        while(second){
            ListNode* temp1= first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            first = temp1;
            
            second->next= temp1;
            second=temp2;
            
        }

        
    }
};
