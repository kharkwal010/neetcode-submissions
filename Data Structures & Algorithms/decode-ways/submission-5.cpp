class Solution {
public:
    bool check (char a, char b){
        int first = a - '0';
        int second = b - '0';
        if (first == 2 && second <= 6){
            return true;
        }
        if (first == 1){
            return true;
        }
        return false;
    }
    int numDecodings(string s) {
        if (s[0]=='0'){
            return 0;
        }
        for (int i=1; i<s.size(); i++){
            if (s[i]=='0' && (s[i-1]!='1' && s[i-1]!='2')){
                return 0;
            }
        }
        
        int single = 1;
        int couple = 0;
        for (int i= s.size()-2; i>=0; i--){
            if (s[s.size()-1]=='0'){
                continue;
            }
            if (s[i]=='0'){
                i--;
                couple = single + couple;
                single = 0;
            }
            else{
                int temp = single;
                single = single + couple;
                if(check(s[i], s[i+1])){
                    couple = temp;
                }
                else couple = 0;
            }
        }
        return single + couple;
        
    }
};
