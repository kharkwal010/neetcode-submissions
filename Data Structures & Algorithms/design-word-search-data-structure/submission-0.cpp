class TrieNode{
    public:
        unordered_map<char, TrieNode*> child;
        bool end = false;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }    
    void addWord(string word) {
       TrieNode* curr = root;
       for(char w: word){
        if(curr->child.find(w)==curr->child.end()){
            curr->child[w]=new TrieNode();
        }
        curr = curr->child[w];
       }
       curr->end = true;
    }

    bool dfs(string word, int i, TrieNode* curr){
        if(i==word.size()) return curr->end;
        bool ans = false;
        if(word[i]!='.'){
            if(curr->child.find(word[i])!=curr->child.end()){
                ans = ans || dfs(word, i+1, curr->child[word[i]]);
            }
        }
        else{
            for(auto &w: curr->child){
                ans = ans || dfs(word, i+1, w.second);
            }
        }
        return ans;
    }
    
    bool search(string word) {
       TrieNode* curr = root;
        return dfs(word, 0, curr);
    }
};
