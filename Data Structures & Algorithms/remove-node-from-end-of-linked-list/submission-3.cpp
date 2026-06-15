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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       // find number of elements;
       int number=0;
       ListNode* curr = head;
       while(curr){
        number++;
        curr=curr->next;
       }
       n = number - n;
       if(n==0){
        return head->next;
       }
       curr=head;
       while(n>1){
        curr=curr->next;
        n--;
       }
       curr->next = curr->next->next;

       return head;
    }
};
