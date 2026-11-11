class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> finished(26,0);
        vector<bool> inside(26,0);
        deque<char> dq;
        vector<int> freq(26,0);
        string res;
        for(char c: s) freq[c-'a']++;
        for(char c: s){
            freq[c-'a']--;
            if(finished[c-'a']) continue;
            if(!inside[c-'a']){
                while(!dq.empty() && dq.back()>c){
                    inside[dq.back()-'a'] = false;
                    dq.pop_back();
                }
                dq.push_back(c);
            }
            
            inside[c-'a'] = true;
            if(freq[c-'a']==0){
                while(dq.front()!=c){
                    res.push_back(dq.front());
                    finished[dq.front()-'a'] = true;
                    dq.pop_front();
                }
                res.push_back(dq.front());
                finished[dq.front()-'a'] = true;
                dq.pop_front();

            }
        }
        return res;        
    }
};