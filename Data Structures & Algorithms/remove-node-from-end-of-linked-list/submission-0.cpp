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
        int number=0;
        ListNode* check= head;
        while(check){
            check=check->next;
            number++;
        }
        int num = number - n;

        ListNode* prev=nullptr;
        ListNode* curr=head;
        if (num==0){
            return curr->next;
        }
        while(head){
            if(num==0){
                head=head->next;
                prev->next = head;
                break;                
            }
            prev=head;
            head=head->next;
            num--;
        }
        return curr;
    }
};
