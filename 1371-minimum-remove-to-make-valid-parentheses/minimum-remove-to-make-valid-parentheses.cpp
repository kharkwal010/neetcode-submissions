class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        stack<char> st;
        for(char c: s){
            if(c==')'){
                if(open>0){
                    open--;
                    st.push(c);
                }
            }
            else if(c=='('){
                open++;
                st.push(c);
            }
            else{
                st.push(c);
            }
        }
        string ans = "";
        while(!st.empty()){
            if(st.top()=='(' && open>0){
                open--;
                st.pop();
                continue;
            }
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};