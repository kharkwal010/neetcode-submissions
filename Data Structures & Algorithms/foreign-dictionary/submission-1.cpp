class Solution {
public:
    unordered_set<char> visited;
    unordered_set<char> path;
    unordered_map<char, unordered_set<char>> adj;
    void dfs(char c, string& ans, bool& loop){
        if(path.count(c)){        // real cycle
            loop = true;
            return;
        }
        if(visited.count(c)) return;

        visited.insert(c);
        path.insert(c);

        for(char nei : adj[c]){
            dfs(nei, ans, loop);
            if(loop) return;
        }

        path.erase(c);
        ans.push_back(c);
    }

    
    string foreignDictionary(vector<string>& words) { 
        unordered_set<char> chars; 
        for(int i=0; i<words.size(); i++){
            for(char ch: words[i]){
                chars.insert(ch);
                adj[ch];
            }
        }     
        for(int i=0; i<words.size()-1; i++){
            int size = min(words[i].size(), words[i+1].size());
            int j=0;
            while(j<size && words[i][j]==words[i+1][j]){
                j++;
            }
            if(j==size){
                if (words[i].size()>words[i+1].size()) return "";
                else continue;
            }
            else adj[words[i][j]].insert(words[i+1][j]);
        }
        string ans;
        bool loop = false;
        for(auto ch: chars){
            dfs(ch, ans, loop);
        }
        if(loop) return "";
        reverse(ans.begin(), ans.end());
        return ans;
                
    }
};
