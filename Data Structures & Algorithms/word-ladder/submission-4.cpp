class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool present = false;
        int len = beginWord.size();
        unordered_map<string, vector<string>> adj;
        wordList.push_back(beginWord);
        for(string w: wordList){
            if(w==endWord) present = true;
            for(int i=0; i<len; i++){
                string key = w.substr(0,i)+ "*" + w.substr(i+1, len-i-1);
                adj[key].push_back(w);
            }
        }
        if(!present) return 0;
        queue<pair<int, string>> q;
        unordered_set<string> visited;
        visited.insert(beginWord);
        q.push({1, beginWord});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(top.second==endWord) return top.first;
            string w = top.second;
            for(int i=0; i<len; i++){
                string key = w.substr(0,i)+ "*" + w.substr(i+1, len-i-1);
                for(auto nei: adj[key]){
                    if(visited.find(nei)==visited.end()){
                        q.push({top.first+1, nei});
                        visited.insert(nei);
                    }
                }
            }
        }
        return 0;

    }
};
