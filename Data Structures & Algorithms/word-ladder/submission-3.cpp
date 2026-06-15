class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool present = false;
        for(string w: wordList){
            if(w==endWord){
                present = true;
                break;
            }
        }
        if(!present) return 0;
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> next;
        for(string word: wordList){
            for(int i=0; i<word.size(); i++){
                string key = word.substr(0, i) + "*" + word.substr(i+1, word.size()-i-1);
                next[key].push_back(word);
            }
        }
        queue<pair<int, string>> q;
        q.push({0, beginWord});
        unordered_set<string> visited;
        visited.insert(beginWord);
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            string word = top.second;
            if(word==endWord) return top.first+1;  
            for(int i=0; i<word.size(); i++){
                string key = word.substr(0, i) + "*" + word.substr(i+1, word.size()-i-1);
                for(string s: next[key]){
                    if(visited.find(s)==visited.end()){
                        visited.insert(s);
                        q.push({top.first+1, s});
                    }                    
                }
            }
        }
        return 0;
    }
};
