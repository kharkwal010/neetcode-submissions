class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1]=='1'){
            return false;
        }
        vector<bool> memo(s.size(), false);
        int j = 0;
        memo[0]=true;
        for(int i=0; i<s.size(); i++){
            if(!memo[i]){
                continue;
            }
            j = max(j, i + minJump);
            int final = min(i+maxJump + 1, (int)s.size());
            while(j<final){
                if(s[j]=='0') memo[j] = true;
                j++;
            }
        }
        if(memo[s.size()-1]){
            return true;
        }
        return false;
    }
};