class Solution {
public:
    int calculate(string s) {
        // here i am going to use (--> INT_MAX; and -(--> INT_MIN;
        long long curr = 0;
        bool add = true;
        stack<long long> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]-'0'>=0 && s[i]-'0'<=9){
                int l=i;
                while(i<s.size() && s[i]-'0'>=0 && s[i]-'0'<=9){
                    i++;
                }
                long long t = stoll(s.substr(l, i-l));
                if(add) st.push(t);
                else st.push(-1*t);
                i--;
            }
            else{
                if(s[i]=='-') add = false;
                else if(s[i]=='+') add = true;
                else if(s[i]=='('){
                    if(add) st.push(LLONG_MAX);
                    else st.push(LLONG_MIN);
                    add=true;
                }
                
                if(s[i]==')'){
                    long long num = 0;
                    while(!(st.top()==LLONG_MIN || st.top()==LLONG_MAX)){
                        // cout<<st.top()<<endl;
                        num += st.top();
                        st.pop();
                    }
                    long long top = st.top();
                    st.pop();
                    if(top==LLONG_MAX){
                        st.push(num);
                    }
                    else{
                        st.push(-1*num);
                    }
                }
                curr = 0;
            }            
        }
        int ans = 0;
        while(!st.empty()){
            cout<<st.top()<<endl;
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};