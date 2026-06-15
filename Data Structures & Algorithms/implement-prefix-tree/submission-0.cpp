class Trienode{
    public:
      unordered_map<char, Trienode*> child;
      bool end = false;
};

class PrefixTree {
public:
    Trienode* root;
    PrefixTree() {
        root = new Trienode();
    }
    
    void insert(string word) {
        Trienode* curr = root;
        for(char w: word){
            if(curr->child.find(w)==curr->child.end()){
                curr->child[w] = new Trienode();
            }
            curr = curr->child[w];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        Trienode* curr= root;
        for(char w: word){
            if(curr->child.find(w)==curr->child.end()){
                return false;
            }
            curr = curr->child[w];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        Trienode* curr= root;
        for(char w: prefix){
            if(curr->child.find(w)==curr->child.end()){
                return false;
            }
            curr = curr->child[w];
        }
        return true;
    }
};
