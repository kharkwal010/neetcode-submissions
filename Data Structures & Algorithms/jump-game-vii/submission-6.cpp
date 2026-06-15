class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1]=='1'){
            return false;
        }
        vector<bool> memo(s.size(), false);
        memo[0]=true;
        for(int i=0; i<s.size(); i++){
            if(!memo[i]){
                continue;
            }
            int final = min(i+maxJump + 1, (int)s.size());
            for(int j = i+minJump; j<final; j++){
                if(s[j]=='0') memo[j] = true;
            }
        }
        if(memo[s.size()-1]){
            return true;
        }
        return false;
    }
};