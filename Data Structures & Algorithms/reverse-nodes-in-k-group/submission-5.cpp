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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* temp;
        while(head){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode* ans = &dummy;
        ListNode* last = ans;
        ListNode* curr = head;
        int count=0;
        while(head && count<k-1){
            head=head->next;
            count++;
        }
        if(!head) return curr;
        ListNode* nxt = head->next;
        head->next = nullptr;
        head=nxt;
        while(true){
            ListNode* term = reverse(curr);
            last->next = term;
            last = curr;
            curr = nxt;
            count= 0;
            while(head && count<k-1){
                head=head->next;
                count++;
            }
            if(!head){
                last->next = curr;
                return ans->next;
            }
            nxt = head->next;
            head->next = nullptr;
            head = nxt;
        }

    }
};
