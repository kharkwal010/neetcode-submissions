class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> contain(26, false);
        vector<bool> visited(26, false);
        vector<int> count(26, 0);
        string ans;
        for(char c: s) count[c-'a']++;
        deque<char> dq;
        for(char c: s){
            if(visited[c-'a']) continue;
            count[c-'a']--;
            if(!contain[c-'a']){
                while(!dq.empty() && dq.back()>c){
                    char ch = dq.back();
                    contain[ch-'a'] = false;
                    dq.pop_back();
                }
                contain[c-'a'] = true;
                dq.push_back(c);
            }
            if(count[c-'a']==0){
                while(!dq.empty() && dq.front()<=c){
                    char ch = dq.front();
                    visited[ch-'a'] = true;
                    ans.push_back(ch);
                    dq.pop_front();
                }
            }
            // cout<<dq.size()<<endl;
        }
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};