class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> count(256,0);
       int start = 0;
       int ans=0;
       for(int i=0; i<s.size(); i++){
            if(count[s[i]-' ']==0){
                count[s[i]-' ']++;
                ans = max(ans, i-start+1);
            }
            else{
                while(s[start]!=s[i]){
                    count[s[start]-' ']--;
                    start++;
                }
                start++;                
            }
       }
       return ans;
    }
};
