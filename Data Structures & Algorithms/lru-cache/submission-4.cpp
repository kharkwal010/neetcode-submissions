class node{
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int key, int val, node* next=nullptr,node* prev = nullptr) : key(key), val(val), next(next), prev(prev){}
    
};
class LRUCache {
public:
    int cap;
    int c_cap=0;
    unordered_map<int, node*> pos;
    node* curr = new node(-1, -1);
    node* first = curr;
    LRUCache(int capacity) {
        cap = capacity;
    }
    void remove(node* c){
        node* p = c->prev;
        node* n = c->next;
        p->next = n;
        if(n) n->prev = p;
        else curr = p;
        pos.erase(c->key);
        delete c;
        return;
    }
    void add(node* nde){
        curr->next = nde;
        nde->prev = curr;
        curr = nde;
        return;
    }
    
    int get(int key) {
        if(!(pos.count(key))) return -1;
        put(key, pos[key]->val);
        return pos[key]->val;
        
    }
    
    void put(int key, int value) {
        node* nde = new node(key, value);
        if(pos.count(key)){
            remove(pos[key]);
            pos[key] = nde;
            add(nde);
            return;            
        }
        else{
            add(nde);
            pos[key] = nde;
        }
        c_cap++;
        if(c_cap>cap){
            remove(first->next);
            c_cap--;
        }        
    }
};
