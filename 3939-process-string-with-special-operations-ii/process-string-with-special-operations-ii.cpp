class Solution {
public:
    char processStr(string s, long long k) {
      long long len = 0;
      for(char c: s){
        if(c=='%') continue;
        else if(c=='*'){
            if(len>0) len--;
        }
        else if(c=='#') len*=2;
        else len++;
      }
        if(k>=len) return '.';
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='*') len++;
            else if(s[i]=='#'){
                if(k>=len/2) k -= len/2;
                len = len/2;
            }
            else if(s[i]=='%') k = len - 1 - k;
            else{
                len--;
                if(len==k) return s[i];
            }
        }
        return s[0];


    }
};