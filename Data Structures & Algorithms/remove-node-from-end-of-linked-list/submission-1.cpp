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
        if(head->next==nullptr){
            return nullptr;
        }
        int number=0;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            number++;
        }
        int num= number-n;
        if(num==0){
            return head->next;
        }
        number = 0;
        ListNode* start = head;
        while(number<num-1){
            head=head->next;
            number++;
        }
        ListNode* temp1 = head;
        temp1=head->next->next;
        head->next=temp1;
        return start;



    }
};
