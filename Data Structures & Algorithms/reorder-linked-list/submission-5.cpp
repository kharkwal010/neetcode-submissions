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
    
    void reorderList(ListNode* head){
        ListNode* mid = head;
        ListNode* temp = head;
        while(temp->next && temp->next->next){
            mid = mid->next;
            temp=temp->next->next;
        }

        
        ListNode* prev = nullptr;
        ListNode* curr = mid->next;
        mid->next = nullptr;

        while(curr){
            ListNode* temp1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp1;
        }

        ListNode* one = head;
        ListNode* two = prev;

       while(two){
            ListNode* temp2 = one->next;
            one->next = two;
            one = one->next;
            two = two->next;
            one->next = temp2;
            one = one->next;
        }

        
        
    }
};
