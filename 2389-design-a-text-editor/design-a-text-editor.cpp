class node {
public:
    node* prev;
    node* next;
    char val;
    node(char val, node* prev = nullptr, node* next = nullptr){
        this->prev = prev;
        this->next = next;
        this->val = val;
    }
};



class TextEditor {
public:
    node* curr;
    node* first;
    TextEditor() {
        curr = new node('#');
        first = curr;
    }
    
    void addText(string text) {
        node* temp = new node(text[0]);
        node* st = temp;
        node* last = temp;
        for(int i=1; i<text.size(); i++){
            node* nde = new node(text[i], temp);
            temp->next = nde;
            temp = temp->next;
            last = temp;
        }
        if(curr->next){
            node* nxt = curr->next;
            last->next = nxt;
            nxt->prev = last;
        }
        curr->next = st;
        st->prev = curr;
        curr = last;
        return;
        
    }
    
    int deleteText(int k) {
        int count = 0;
        while(k>0 && curr!=first){
            node* temp = curr->prev;
            temp->next = curr->next;
            if(curr->next) curr->next->prev = temp;
            node* d = curr;
            curr = temp;
            delete(d);
            k--;
            count++;
        }
        return count;
    }
    
    string cursorLeft(int k) {
        string ans = "";
        while(k>0 && curr!=first){
            curr = curr->prev;
            k--;
        }
        node* temp = curr;
        for(int i=0; i<10; i++){
            if(temp==first) break;
            ans.push_back(temp->val);
            temp = temp->prev;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string cursorRight(int k) {
         string ans = "";
        while(k>0 && curr->next){
            curr = curr->next;
            k--;
        }
        node* temp = curr;
        for(int i=0; i<10; i++){
            if(temp==first) break;
            ans.push_back(temp->val);
            temp = temp->prev;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */