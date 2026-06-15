class node{
    public:
        int val;
        int key;
        node* next;
        node* prev;
        node(int key, int val, node* prev = nullptr, node* next = nullptr): key(key), val(val), prev(prev), next(next){}
};

class LRUCache {
public:
    int cap;
    unordered_map<int, node*> memo;
    node dummy{-1,-1};
    node* curr = &dummy;
    node* first = curr;
    int terms = 0;
    void remove(node* no){
        node* p = no->prev;
        node* n = no->next;
        if(p) p->next = n;
        if(n) n->prev = p;
        if(no==curr) curr= curr->prev;
        memo.erase(no->key);
        delete no;
        return;
    }
    void insert(node* n, node* curr){
        curr->next = n;
        n->prev = curr;
    }
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(memo.find(key)==memo.end()){
            return -1;
        }
        put(key, memo[key]->val);
        return memo[key]->val;
    }
    
    void put(int key, int value) {
        node* new_n = new node(key, value);
        if(memo.find(key)==memo.end()){
            terms++;
        }
        else{
            remove(memo[key]);
        }
        insert(new_n, curr);
        curr=curr->next;
        memo[key]=new_n;
        if(terms>cap){  
            terms--;          
            remove(first->next);
        }
    }
};
