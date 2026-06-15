class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word2.size()+1, vector<int>(word1.size()+1, 0)); 
        int len1 = word1.size();
        int len2= word2.size();
        
        for(int i = word1.size()-1; i>=0; i--){
            dp[len2][i]= dp[len2][i+1]+1;
        }  
        for(int i=word2.size()-1; i>=0; i--){
            dp[i][len1] = dp[i+1][len1]+1;
        }

        for(int i=word2.size()-1; i>=0; i--){
            for(int j=word1.size()-1; j>=0; j--){
                if(word1[j] == word2[i]){
                    dp[i][j]= dp[i+1][j+1];
                }
                else{
                    dp[i][j]= 1+min(min(dp[i][j+1], dp[i+1][j]),dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
