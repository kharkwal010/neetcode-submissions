class Solution {
public:
    bool checkValidString(string s) {
        int minopen = 0;
        int maxopen = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                minopen++;
                maxopen++;
            }
            else if(s[i]==')'){
                minopen--;
                maxopen--;
                if(maxopen<0){
                    return false;
                }
                else if(minopen<0){
                    minopen=0;
                }
            }
            else if(s[i]=='*'){
                maxopen++;
                minopen--;
                if(minopen<0){
                    minopen=0;
                }
                
            }           
        }
        if(minopen==0){
            return true;
        }
        return false;
    }
};
