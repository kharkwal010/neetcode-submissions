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
    ListNode* reverse(ListNode* head, int k){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(k>0){
            ListNode* temp = curr->next;
            curr->next= prev;
            prev = curr;
            curr = temp;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 1;
        ListNode* ans;
        ListNode* one = head;
        while(count<k){
            one=one->next;
            if(!one) return head;
            count++;
        }
        ans = one;
        ListNode* next = one->next;
        while(head){
            ListNode* prev = reverse(head, k);
            bool present = true;
            ListNode* temp = next;
            if(!temp) return ans;
            count = 1;
            while(count<k){
                temp = temp->next;
                if(!temp){
                     present = false;
                     break;
                }
                count++;
            }
            if(present){
                prev->next = temp;
                head=next;
                next = temp->next;
            }
            else{
                prev->next = next;
                return ans;
            }
        }
        return ans;

    }
};
