class Node{
    public:
        int val;
        int key;
        int freq;
        Node* prev;
        Node* next;
        Node(int key, int val, int freq=1, Node* prev = nullptr, Node* next = nullptr){
            this->val = val;
            this->key = key;
            this->freq = freq;
            this->prev = prev;
            this->next = next;
        }
};


class LFUCache {
public:
    int cap;
    int index = 0;
    int count = 0;
    unordered_map<int, pair<Node*, Node*>> match;
    unordered_map<int, Node*> term;
    LFUCache(int capacity) {
        cap = capacity;
    }

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        if(next) next->prev = prev;
        return;
    }

    void insert(Node* tail, Node* newn){
        Node* prev = tail->prev;
        prev->next = newn;
        newn->prev = prev;
        newn->next = tail;
        tail->prev = newn;
        return;
    }

    void create(Node* node, int i){
        Node* first = new Node(-1,-1);
        Node* last = new Node(-1,-1);
        first->next = last;
        last->prev = first;
        match[i] = {first, last};
        insert(match[i].second, node);
    }

    void process(int key){
        Node* nde = term[key];
        remove(term[key]);
        int freq = nde->freq;
        if(freq == index && match[freq].first->next == match[freq].second){
            index++;
        }
        nde->freq+=1;
        if(!match.count(freq+1)) create(nde, freq+1);
        else insert(match[freq+1].second, nde);
        term[key] = nde;
    }
    

    
    int get(int key) {
        if(term.count(key)){
            process(key);
            return term[key]->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(term.count(key)){
           term[key]->val = value;
           process(key);
        }
        else{
            count++;
            if(count>cap){
                Node* toDelete = match[index].first->next;
                remove(toDelete);

                term.erase(toDelete->key);
                delete toDelete;
                count--;
            }
            index = 1;
            Node* nde = new Node(key, value);
            if(!match.count(1)) create(nde, 1);
            else insert(match[1].second, nde);   
            term[key] = nde;         
        }
        
        return;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */