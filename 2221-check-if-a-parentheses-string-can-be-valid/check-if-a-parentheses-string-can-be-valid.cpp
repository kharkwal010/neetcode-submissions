class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2!=0) return false;
        int minopen = 0;
        int maxopen = 0;
        for(int i=0; i<s.size(); i++){
            if(locked[i]=='0'){
                if(minopen>0) minopen--;
                maxopen++;
            }
            else if(s[i]==')'){
                if(minopen>0) minopen--;
                maxopen--;
                if(maxopen<0) return false;
            }
            else{
                minopen++;
                maxopen++;
            }
            // cout<<i<<" "<<minopen<<" "<<maxopen<<endl;
        }
        return (minopen==0);
    }
};