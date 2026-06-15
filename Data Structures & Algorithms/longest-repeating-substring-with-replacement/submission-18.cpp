class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int maxf=0;
        int ans=0;
        int start = 0;
        for(int i=0; i<s.size(); i++){
            count[s[i]-'A']++;
            int freq = count[s[i]-'A'];
            maxf = max(freq, maxf);
            if(i-start+1 - maxf<=k){
                ans = max(ans, i-start+1);
            }
            else{
                count[s[start]-'A']--;
                start++;
            }
        }
        return ans;
    }
};
