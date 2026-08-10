class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') open++;
            else if(s[i]==')'){
                if(i+1==s.size() || s[i+1]!=')'){
                    count++;
                }
                else i++;
                open--;
            }
            if(open<0){
                open=0;
                count++;
            }
        }
        count += open*2;
        return count;
    }
};