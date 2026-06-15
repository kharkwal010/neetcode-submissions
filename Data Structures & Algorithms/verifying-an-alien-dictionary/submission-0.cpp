class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, vector<char>> adj;
        for(int i=1; i<words.size(); i++){
            for(int j=0; j<words[i-1].size(); j++){
                if(j>=words[i].size()) return false;
                if(words[i][j]!=words[i-1][j]){
                    adj[words[i][j]].push_back(words[i-1][j]);
                    break;
                }
            }
        }
        vector<int> visited(26, 0);
        for(char c: order){
            if(adj.find(c)!=adj.end()){
                for(char ad: adj[c]){
                    visited[ad-'a'] = 1;
                }
            }
            if(visited[c-'a']==1) return false;
        }
        return true;
    }
};