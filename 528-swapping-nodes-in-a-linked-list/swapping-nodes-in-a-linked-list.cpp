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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        if(n-k+1==k) return head;
        int a = n - k + 1;
        int b = k;
        if(b<a) swap(b, a);
        ListNode *prev1 = nullptr, *prev2 = nullptr, *next1 = nullptr;
        ListNode *curr1 = nullptr, *curr2 = nullptr, *next2 = nullptr;
        int cnt = 1;
        temp = head;
        while(temp){
            if(cnt==a-1) prev1 = temp;
            if(cnt==a){
                curr1 = temp;
                next1 = temp->next;
            }
            if(cnt==b-1){
                prev2 = temp;
                curr2 = temp->next;
                next2 = temp->next->next;
            }
            cnt++;
            temp = temp->next;
        }
        if(b-a==1){
            if(a==1){
                curr2->next = curr1;
                curr1->next = next2;
                return curr2;
            }
            else{
                prev1->next = curr2;
                curr2->next = curr1;
                curr1->next = next2;
                return head;
            }
            
        }

        prev2->next = curr1;
        curr1->next = next2;
        if(prev1) prev1->next = curr2;
        curr2->next = next1;
        if(a==1) return curr2;
        return head;

    }
};