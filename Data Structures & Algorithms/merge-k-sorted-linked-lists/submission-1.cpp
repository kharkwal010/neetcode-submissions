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
    ListNode* sorting(ListNode* one, ListNode* two){
        ListNode dummy(0);
        ListNode* first = &dummy;
        while(one && two){
            if(one->val<=two->val){
                first->next = one;
                one = one->next;
            }
            else{
                first->next = two;
                two = two->next;
            }
            first = first->next;
        }
        if(!one && two) swap(one, two);
        first->next = one;
        return dummy.next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(r==l) return lists[l];
        else if(r<l) return nullptr;
        int m = (l+r)/2;
        ListNode* one = merge(lists, l, m);
        ListNode* two = merge(lists, m+1, r);
        return sorting(one, two);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }
};
