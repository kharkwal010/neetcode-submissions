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
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = head;
        ListNode* curr = head;
        int n = k;
        while(n>1){
            if(!curr) return head;
            curr=curr->next;
            n--;
        }
        ListNode* ans = curr;
        ListNode* prev_s;
        while(curr){
            prev_s = curr->next;
            curr->next = nullptr;
            prev = reverse(prev);
            curr = prev_s;
            n = k;
            while(n>1){
                if(!curr) break;
                curr= curr->next;
                n--;
            }
            if(curr){
               prev->next = curr;
               prev = prev_s;
            }
            else prev->next = prev_s;
        }
        return ans;

    }
};
