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
        ListNode* curr = head;
        ListNode* next = curr->next;
        while(next){
            int one = curr->val;
            int two = next->val;
            int div = gcd(one, two);
            curr->next = new ListNode(div);
            curr= curr->next;
            curr->next = next;
            curr = curr->next;
            next = next->next;
        }
        return head;
    }
};