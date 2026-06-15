class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int maxf = 0;
        int ans = 0;
        int start = 0;
        int extra = 0;
        
        for(int i=0; i<s.size(); i++){
           count[s[i]-'A']++;
           maxf = max(maxf, count[s[i]-'A']);
           extra = i - start + 1 - maxf;
           if(extra>k){
            count[s[start]-'A']--;
            start++;
            continue;            
           }
           ans = max(ans, i-start+1);

        }
        return ans;
    }
};
