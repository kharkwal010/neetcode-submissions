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
    ListNode* reverse(ListNode* l){
        ListNode* prev = nullptr;
        ListNode* temp;
        while(l){
            temp = l->next;
            l->next = prev;
            prev = l;
            l = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* one = reverse(l1);
        ListNode* two = reverse(l2);
        int remain = 0;
        ListNode* curr = new ListNode(0);
        ListNode* ans = curr;
        while(one && two){
            int sum = one->val + two->val + remain;
            ListNode* nxt = new ListNode(sum%10);
            remain = sum/10;
            curr->next = nxt;
            curr = curr->next;
            one = one->next;
            two = two->next;
        }  
        if(!one && two) swap(one, two);
        while(one){
            int sum = one->val + remain;
            ListNode* nxt = new ListNode(sum%10);
            remain = sum/10;
            curr->next = nxt;
            curr = curr->next;
            one = one->next;
            two = two->next;
        }  
        if(remain==1){
            ListNode* nxt = new ListNode(1);
            curr->next = nxt;
        }   
        ans = ans->next;
        return reverse(ans);
         
    }
};