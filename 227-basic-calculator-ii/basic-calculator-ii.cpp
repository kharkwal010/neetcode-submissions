class Solution {
public:
    int calculate(string s) {
        stack<char> op;
        stack<int> terms;
        int i=0;
        while(i<s.size()){
            if(!(s[i]-'0'>=0 && s[i]-'0'<=9)){
                if(s[i]!=' ') op.push(s[i]);
                i++;
            }
            else{
                int j = i;
                while(i<s.size() && (s[i]-'0'>=0 && s[i]-'0'<=9)){
                    i++;
                }
                int t = stoi(s.substr(j, i-j));
                if(op.empty() || op.top()=='+' || op.top()=='-'){
                    if(!op.empty() && op.top()=='-'){
                        t *= -1;
                        op.pop();
                    }
                    terms.push(t);
                }
                else{
                    int prev = terms.top();
                    terms.pop();
                    int curr;
                    if(op.top()=='/') curr = prev / t;
                    else curr = prev*t;
                    op.pop();
                    terms.push(curr);
                }
            }            
        }
        while(terms.size()>1){
            int one = terms.top();
            terms.pop();
            int two = terms.top();
            terms.pop();
            terms.push(one + two);
        }
        return terms.top();
    }
};