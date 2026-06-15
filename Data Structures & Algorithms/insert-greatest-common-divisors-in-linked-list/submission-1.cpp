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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr= head;
        int one = curr->val;
        while(curr->next){
            int two = curr->next->val;
            ListNode* temp = curr->next;
            int num = gcd(one, two);
            ListNode* node = new ListNode(num);
            curr->next = node;
            curr = curr->next;
            curr->next = temp;
            curr = curr->next;
            one = two;            
        }
        return head;
    }
};