class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') st.push(INT_MAX);
            else{
                int curr = 1;
                if(st.top()==INT_MAX){
                    st.pop();                    
                }
                else{
                    curr = st.top()*2;
                    st.pop();
                    st.pop();
                }
                if(!st.empty() && st.top()!=INT_MAX){
                    curr = curr + st.top();
                    st.pop();
                }
                st.push(curr);
            }
        }
        return st.top();
    }
};