class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char c: s){
            if(c==')'){
                string temp = "";
                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(char t: temp) st.push(t);
            }
            else st.push(c);
        }
        string ans = "";
        while(!st.empty()){
            char c = st.top();
            ans.push_back(c);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};