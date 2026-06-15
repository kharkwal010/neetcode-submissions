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
    ListNode* merge(ListNode* one, ListNode* two){
        ListNode dummy(0);
        ListNode* curr = &dummy;       
        while(one &&  two){
            if(one->val<=two->val){
                curr->next = one;
                one = one->next;
            }
            else{
                curr->next = two;
                two = two->next;
            }
            curr=curr->next;
        }
        if(one) curr->next = one;
        if(two) curr->next = two;
        return dummy.next;
    }

    ListNode* mergek(vector<ListNode*>& lists, int l, int r){
        if(l==r) return lists[l];
        int m = (l+r)/2;
        ListNode* one = mergek(lists, l, m);
        ListNode* two = mergek(lists, m+1, r);
        return merge(one, two);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return mergek(lists, 0, lists.size()-1);
    }
};
