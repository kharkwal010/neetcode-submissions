class TrieNode{
    public:
        unordered_map<char, TrieNode*> child;
        bool end = false;
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* head = root;
        for(char w: word){
            if(!head->child[w]){
                head->child[w]= new TrieNode();
            }
            head = head->child[w];
        }
        head->end=true;
    }
    
    bool search(string word) {
        TrieNode* head = root;
        for(char w: word){
            if(!head->child[w]) return false;
            head = head->child[w];
        }
        return head->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* head = root;
        for(char w: prefix){
            if(!head->child[w]) return false;
            head = head->child[w];
        }
        return true;
    }
};
