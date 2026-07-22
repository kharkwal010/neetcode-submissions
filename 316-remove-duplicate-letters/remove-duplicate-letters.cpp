class Solution {
public:
    string removeDuplicateLetters(string s) {
       stack<char> st;
       vector<int> freq(26, 0);
       for(char c: s){
            freq[c-'a']++;
       }
       vector<bool> inside(26, false);
       for(char c: s){
            freq[c-'a']--;
            if(inside[c-'a']) continue;
            if(st.empty() || st.top()<c){
                st.push(c);
                inside[c-'a'] = true;
            }
            else{
                while(!st.empty() && st.top()>c){
                    if(freq[st.top()-'a']==0) break;
                    inside[st.top()-'a'] = false;
                    st.pop();
                }
                st.push(c);
                inside[c-'a'] = true;                
            }
       }
       string ans;
       while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
       }
       reverse(ans.begin(), ans.end());
       return ans;
    }
};