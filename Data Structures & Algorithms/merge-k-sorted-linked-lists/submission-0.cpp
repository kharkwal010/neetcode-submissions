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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode dummy(0);
        ListNode* ans = &dummy;
        ListNode* curr = ans;
        while(list1 && list2){
            if(list1->val<=list2->val){
                ans->next = list1;
                list1 = list1->next;
                ans = ans->next;
            }
            else{
                ans->next = list2;
                list2 = list2->next;
                ans = ans->next;
            }
        }
        if(list1) ans->next = list1;
        else if(list2) ans->next = list2;
        return curr->next;
    }
        ListNode* mergek(vector<ListNode*>& lists, int l, int r) {
            if(l==r) return lists[l];
            int m = (l+r)/2;
            ListNode* left = mergek(lists, l, m);
            ListNode* right = mergek(lists, m+1, r);
            return merge(left, right);
                    
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return mergek(lists,0, lists.size()-1);
        
    }
};
