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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        int block = n / k;
        int extra = n % k;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        vector<ListNode*> res(k);
        for(int i=0; i<k; i++){
            res[i] = curr;
            for(int j = 0; j<block; j++){
                prev = curr;
                curr = curr->next;
            }
            if(extra>0){
                extra--;
                prev = curr;
                curr = curr->next;
            }
            if(prev) prev->next = nullptr;
        }
        return res;
    }
};