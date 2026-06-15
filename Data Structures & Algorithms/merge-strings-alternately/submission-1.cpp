class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int n = min(word1.size(), word2.size());
        for( int i=0; i<n; i++){
            ans = ans + word1[i] + word2[i];
        }
        if(word1.size()<word2.size()){
            for(int i=n; i<word2.size(); i++){
                ans = ans + word2[i];
            }
        }
        else if(word1.size()>word2.size()){
            for(int i=n; i<word1.size(); i++){
                ans = ans + word1[i];
            }
        }
        return ans;
    }
};