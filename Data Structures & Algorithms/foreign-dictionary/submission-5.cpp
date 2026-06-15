class Solution {
public:
    unordered_map<char, vector<char>> adj;
    unordered_set<char> visited;
    
    string foreignDictionary(vector<string>& words) {
        vector<int> present(26,0);
        vector<int> indeg(26,0);
        for(string w: words){
            for(char c: w){
                present[c-'a'] = 1;
            }
        }
        int count = 0;
        for(int c: present){
            count+=c;
        }

        if(words.size()==1) return words[0];
        for(int i=0; i<words.size()-1; i++){
            for(int j=0; j<words[i].size(); j++){
                if(j>=words[i+1].size()) return "";
                if(words[i][j]!=words[i+1][j]){
                    adj[words[i][j]].push_back(words[i+1][j]);
                    indeg[words[i+1][j]-'a']++;
                    break;
                }
            }            
        }
        string ans;
        queue<char> q;
        for(int i=0; i<26; i++){
            if(indeg[i]==0){
                if(present[i]==0) indeg[i]=-1;
                else{
                    q.push('a'+i);
                    visited.insert('a'+i);
                }
            }
        }
        while(!q.empty()){
            char top = q.front();
            q.pop();
            ans.push_back(top);
            for(char nei: adj[top]){
                if(!visited.count(nei)){
                    indeg[nei-'a']--;
                    if(indeg[nei-'a']==0) q.push(nei);
                }
            }
        }
        if(ans.size()==count) return ans;
        return "";
        
    }
};

