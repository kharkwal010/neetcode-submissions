class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
       vector<int> dp(text1.size()+1,0);
       vector<int> prev;
       for(int i=text2.size()-1; i>=0; i--){
            prev = dp;
            for(int j=text1.size()-1; j>=0; j--){
                if(text1[j]==text2[i]) dp[j] = prev[j+1] + 1;
                else dp[j] = max(dp[j], dp[j+1]);
            }
       }
       return dp[0];
    }
};
