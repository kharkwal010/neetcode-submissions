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
       ListNode* prev = nullptr;
       curr = head;
       while(curr){
        ListNode* temp = curr->next;
        if(n==0){
            prev->next = temp;
            break;
        }
        prev = curr;
        curr=temp;
        n--;
       }
       return head;
    }
};
