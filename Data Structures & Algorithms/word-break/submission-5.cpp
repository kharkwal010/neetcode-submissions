class Solution {
public:
    unordered_map<int, bool> memo;
    bool dp(string s, vector<string> wordDict, int curr){
        if (curr == s.size()){
            return true;
        }
        if (memo.find(curr)!= memo.end()){
            return memo[curr];
        }
        bool ans = false;
        for(string word: wordDict){
            int l = word.size();
            string sub = s.substr(curr, l);
            if(sub == word){
                if(dp(s, wordDict, curr+l)){
                    return true;
                }
            }
        }
            memo[curr]= false;
            return false;
       
        
    }
        
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = dp(s, wordDict, 0);
        return ans;
    }
};
