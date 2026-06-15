class Solution {
public:
    vector<int> partitionLabels(string s) {
       vector<int> ans;
       queue<int> q;
       vector<int> count(26,0);
       for(char c: s){
        count[c-'a']++;
       }
       int l = 0;
       vector<bool> visited(26, false);
       for(int r=0; r<s.size(); r++){
            count[s[r]-'a']--;
            if(visited[s[r]-'a']==false){
                visited[s[r]-'a']=true;
                q.push(s[r]-'a');
            }
            while(!q.empty() && count[q.front()]==0) q.pop();
            if(q.empty()){
                ans.push_back(r-l+1);
                l=r+1;
            }
       }
       return ans;
    }
};
