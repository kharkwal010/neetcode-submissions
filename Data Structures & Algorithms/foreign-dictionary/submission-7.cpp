class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<unordered_set<int>> nei(26);
        vector<int> indegree(26, 0);
        for(int i=0; i<words.size()-1; i++){
            int x=0;
            int y=0;
            while(x<words[i].size() && y<words[i+1].size()){
                if(words[i][x]==words[i+1][y]){
                    x++;
                    y++;
                }
                else{
                    if(!nei[words[i][x]-'a'].count(words[i+1][y]-'a')) indegree[words[i+1][y]-'a']++;
                    nei[words[i][x]-'a'].insert(words[i+1][y]-'a');
                    break;
                }
            }
            if(y==words[i+1].size() && x!=words[i].size()) return "";
        }
        vector<int> present(26,0);
        for(string s: words){
            for(char w: s){
                present[w-'a'] = 1;
            }
        }
        int count = 0;
        for(int i=0; i<26; i++){
            count += present[i];
        }
        queue<char> q;
        for(int i=0; i<26; i++){
            if(present[i]==1){
                if(indegree[i]==0) q.push(i+'a');
            }
        }
        string s;
        int visited = 0;
        while(!q.empty()){
            char c = q.front();
            q.pop();
            visited++;
            s.push_back(c);
            for(int ele: nei[c-'a']){
                indegree[ele]--;
                if(indegree[ele]==0) q.push(ele+'a');
            }
        }
        if(visited!=count) return "";
        return s;        
    }
};
