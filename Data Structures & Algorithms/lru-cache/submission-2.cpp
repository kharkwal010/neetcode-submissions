struct node{
    int key;
    int val;
    node* prev;
    node* next;
    node(int key, int val, node* prev = nullptr, node* next = nullptr): key(key), val(val), prev(prev), next(next){}
};

class LRUCache {
public:
    unordered_map<int, node*> memory;
    int cap;
    node* first;
    node* curr;
        void remove(node* n){
            node* pr = n->prev;
            node* nt = n->next;
            pr->next = nt;
             if(nt) nt->prev = pr;
            if(n==curr){
                curr= curr->prev;
            }
            delete n;
            return;
        }

        void insert(node* n, node* curr){
            curr->next = n;
            n->prev = curr;
            return;
        }

    LRUCache(int capacity) {
        cap = capacity;
        memory.clear();
        first = new node(-1,-1);
        curr = first;
    }
    
    int get(int key) {
        if(memory.find(key)!=memory.end()){
            put(memory[key]->key, memory[key]->val);
            return memory[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(memory.find(key)!=memory.end()){
            remove(memory[key]);
        }
        node* newnode = new node(key, value);
        memory[key] = newnode;
        insert(newnode, curr);
        curr = curr->next;
        if(memory.size()>cap){
            memory.erase(first->next->key);
            remove(first->next);
        }
    }
};
