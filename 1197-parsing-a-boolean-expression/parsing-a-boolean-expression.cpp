class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char c: expression){
            if(c==',') continue;
            if(c==')'){
                bool a = false;
                bool b = false;

                while(st.top()!='('){
                    if(st.top()=='t') a = true;
                    else b = true;
                    // cout<<st.top()<<endl;
                    st.pop();
                }

                st.pop();
                char op = st.top();
                st.pop();
                if(op=='!'){
                    if(a) st.push('f');
                    else st.push('t');
                }
                else{
                    if(op=='&'){
                        if(a && b) st.push('f');
                        else if(a && !b) st.push('t');
                        else st.push('f');
                    }
                    else if(op=='|'){
                        if(a && b) st.push('t');
                        else if(a && !b) st.push('t');
                        else st.push('f');
                    }
                }   
            }
            else{
                st.push(c);
            }
        }
        char ans = st.top();
        // cout<<ans<<endl;
        if(ans=='t') return true;
        return false;
    }
};