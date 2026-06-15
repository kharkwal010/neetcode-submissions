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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        int count1=0;
        int count2 = 0;
        ListNode* tone = l1;
        ListNode* tsecond = l2;
        while (tone){
            count1++;
            tone= tone->next;
        }
        while (tsecond){
            count2++;
            tsecond = tsecond->next;
        }
        ListNode* one;
        ListNode* second;

        if (count1 > count2) {
            one = l1;
            second = l2;
        } else {
            one = l2;
            second = l1;
        }
         ListNode dummy(0);
        ListNode* result = &dummy;


        int carry =0;
        while (second){
            int temp1 = one->val;
            int temp2 = second->val;
            int temp3 = temp1+ temp2 + carry;
            int value = temp3%10;
            result->next = new ListNode(value);
            carry = temp3/10;
            result = result->next;
            one=one->next;
            second = second->next;
            
        }
        while(one){
            int temp = one->val;
            int sum = temp + carry;
            int value = (sum)%10;
            carry = sum/10;
            result->next = new ListNode(value);
            result = result->next;
            one=one->next;
        }
       if (carry == 1) {
            result->next = new ListNode(1);
        }
        return dummy.next;
        
    }

};
