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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted = head;
        head = head->next;
        sorted->next = nullptr;
        while(head){
            ListNode* value = head;
            head = head->next;
            value->next = nullptr;

            ListNode* curr = sorted;
            if(curr->val>value->val){
                value->next = sorted;
                sorted = value;
            }
            else{
                while(curr->next && curr->next->val<value->val){
                    curr=curr->next;
                }
                ListNode* temp = curr->next;
                curr->next = value;
                value->next = temp;
            }
        }
        return sorted;
    }
};