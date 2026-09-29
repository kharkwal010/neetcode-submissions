class Solution {
public:
    string robotWithString(string s) {
        string next = s;
        next[s.size()-1] = 'z'+1;
        for(int i=s.size()-2; i>=0; i--){
            next[i] = min(next[i+1], s[i+1]);
        }
        stack<char> st;
        string ans = "";
        // cout<<next<<endl;
        for(int i=0; i<s.size(); i++){
            st.push(s[i]);
            while(!st.empty() && st.top()<=next[i]){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;

    }
};