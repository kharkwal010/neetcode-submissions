class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int k): val(k), next(nullptr){}

};

class MyHashSet {
public:

    vector<ListNode*> arr;
    MyHashSet() {
        arr.resize(10000);
        for(auto& ele: arr){
            ele = new ListNode(-1);
        }
    }
    
    void add(int key) {
        ListNode* curr = arr[key%10000];
        while(curr->next){
            if(curr->next->val==key) return;
            curr= curr->next;
        }
        curr->next = new ListNode(key);
        return;
    }
    
    void remove(int key) {
        ListNode* curr = arr[key%10000];
        while(curr->next){
            if(curr->next->val==key){
                curr->next = curr->next->next;
                return;
            }
            curr= curr->next;
        }
    }
    
    bool contains(int key) {
        ListNode* curr = arr[key%10000];
        while(curr->next){
            if(curr->next->val==key) return true;
            curr= curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */