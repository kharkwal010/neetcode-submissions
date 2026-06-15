class MyHashMap {
public:
    struct ListNode{
        int key;
        int val;
        ListNode* next;
        ListNode(int key = -1, int val = -1, ListNode* next= nullptr) : key(key), val(val), next(next) {}
    };
    vector<ListNode*> mapping;
    int hash(int key){
        return key%1000;  // here i am keeping the size of hash map = 1000;
    }

    MyHashMap() {
        mapping.resize(1000);
        for(auto& value: mapping){
            value = new ListNode(0,-1);
        }
    }
    
    void put(int key, int value) {
        ListNode* curr = mapping[hash(key)];
        while(curr->next){
            if(curr->next->key==key){
                curr->next->val = value;
                return;
            }
            curr = curr->next;
        }
        curr->next = new ListNode(key,value);
        return;
    }
    
    int get(int key) {
        ListNode* curr = mapping[hash(key)]->next;
        while(curr){
            if(curr->key==key){
                return curr->val;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* curr = mapping[hash(key)]->next;
        ListNode* prev = mapping[hash(key)];    
        while(curr){
            if(curr->key==key){
                prev->next = curr->next;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        delete curr;  
        return;     
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */