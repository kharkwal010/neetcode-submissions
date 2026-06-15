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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = k-1;
        ListNode* kth = head;
        while(kth && count>0){
            kth= kth->next;
            count--;
        }
        if(!kth) return head;

        ListNode* ans = kth;
        int moves;
        ListNode* prev = nullptr;
        while(true){
            moves = k;
            ListNode* pr = head;
            while(moves>0){
                ListNode* temp = head->next;
                head->next = prev;
                prev = head;
                head = temp;
                moves--;
            }
            
            kth = head;
            count = k-1;
            while(kth && count>0){
                kth= kth->next;
                count--;
            }
            if(!kth){
                pr->next = head;
                return ans;
            }
            else{
                pr->next = kth;
            }
        }

    }
};
