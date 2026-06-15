class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(int i=0; i<s.size(); i++){
            if(st.empty() || st.top().first!=s[i]){
                st.push({s[i], 1});
            }
            else if(st.top().first==s[i]){
                st.push({s[i], st.top().second + 1});
            }
            if(!st.empty() && st.top().second==k){
                char c = st.top().first;
                while(!st.empty() && st.top().first==c) st.pop();
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};