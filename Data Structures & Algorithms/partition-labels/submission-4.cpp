class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,0);
        for(char c: s){
            freq[c-'a']++;
        }
        vector<int> ans;
        vector<bool> visited(26, false);
        queue<char> q;
        int start = 0;
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']--;
            if(!visited[s[i]-'a']){
                q.push(s[i]);
                visited[s[i]-'a'] = true;
            }
            while(!q.empty()){
                char top = q.front();
                if(freq[top-'a']==0) q.pop();
                else break;
            }
            if(q.empty()){
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        return ans;
    }
};
