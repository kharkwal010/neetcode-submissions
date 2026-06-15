class Solution {
public:
    bool isNumber(string s){
        for(int i=0; i<s.size(); i++){
            if(s[i]<'0' || s[i]>'9'){
                return false;
            }
        }
        return true;
    }
    string decodeString(string s) {
        stack<string> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]-'0'>=0 && s[i]-'0'<=9){
                int start=i;
                while(s[i]!='['){
                    i++;
                }
                string term = s.substr(start, i-start);
                st.push(term);
            }
            else if(s[i]-'a'>=0 && s[i]-'a'<26){                
                if(st.empty() || isNumber(st.top())){
                    st.push(string(1,s[i]));
                }
                else{
                    string till = st.top();
                    st.pop();
                    st.push(till+s[i]);
                }
            }
            else if(s[i]==']'){
                string str = st.top();
                st.pop();
                int n = stoi(st.top());
                st.pop();
                string term2;
                for(int i=0; i<n; i++){
                    term2 = term2 + str;
                }
                if(st.empty() || isNumber(st.top())){
                    st.push(term2);
                }
                else{
                    string till = st.top();
                    st.pop();
                    st.push(till+term2);
                }
            }
        }
        return st.top();
    }
};