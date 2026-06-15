class Solution {
public:
    bool checkValidString(string s) {
       int maxopen = 0;
       int minopen =0;
       for (int i=0; i<s.size(); i++){
        if(s[i]=='('){
            minopen++;
            maxopen++;
        }
        else if(s[i]=='*'){
            minopen--;
            maxopen++;
        }
        else if(s[i]==')'){
            minopen--;
            maxopen--;
        }
        if (minopen<0){
            minopen =0;
        }
        if (maxopen<0){
            return false;
        }
       }
        if (minopen==0){
            return true;
        }
        return false;
    }
};
