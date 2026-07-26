class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long term = 0;
        int sign = 1;
        int i=0;
        stack<int> op;
        while(i<s.size()){
            if(!(s[i]-'0'<=9 && s[i]-'0'>=0)){
                if(s[i]=='+') sign = 1;
                else if(s[i]=='-') sign = -1;
                else if(s[i]=='('){
                    st.push(term);
                    term = 0;
                    op.push(sign);
                    sign = 1;
                }
                else if(s[i]==')'){
                    long long t = st.top();
                    st.pop();
                    term = term*op.top()+t;
                    op.pop();
                }
                i++;
            }
            else{
                long long t = 0;
                while(i<s.size() && (s[i]-'0'<=9 && s[i]-'0'>=0)){
                    t = 10*t + s[i]-'0';
                    i++;
                }
                term += sign*t;
            }
        }
        return term;
    }
};