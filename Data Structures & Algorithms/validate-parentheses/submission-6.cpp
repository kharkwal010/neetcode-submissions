class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> br;
        br['}']='{';
        br[')']='(';
        br[']']='[';
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stack.push(s[i]);
            }
            else{
                if(stack.empty() || br[s[i]]!=stack.top()){
                    return false;
                }
                else stack.pop();
            }
        }
        if(stack.empty()){
            return true;
        }
        return false;
       
    }
};
