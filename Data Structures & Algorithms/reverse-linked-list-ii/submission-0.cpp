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
    ListNode* rev(ListNode* curr, int count){
        ListNode* prev = nullptr;
        ListNode* one = curr;
        while(count>=0){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count--;
        }
        if(curr) one->next = curr;
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode dummy(0);
       ListNode* par = &dummy;
       ListNode* curr = head;
       int count = right - left;
       while(left>2){
            curr = curr->next;
            left--;
       }
       if(left!=1){
            par = curr;
            curr = curr->next;
       }
       
       par->next = rev(curr,count);

       if(left!=1) return head;
       else return par->next;

    }
};