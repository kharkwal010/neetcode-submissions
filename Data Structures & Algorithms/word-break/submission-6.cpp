class Solution {
public:
    unordered_map<int, bool> memo;
    bool dp(string s, vector<string> wordDict, int curr){
        if(curr==s.size()){
            return true;
        }
        if(curr>s.size()){
            return false;
        }
        if(memo.find(curr)!=memo.end()){
            return memo[curr];
        }
        int ans = false;
        for(string word: wordDict){
            string sub = s.substr(curr, word.size());
            if(sub==word){
                ans = ans || dp(s, wordDict, curr+word.size());
            }
        }
        memo[curr]=ans;
        return ans;

    }
        
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = dp(s, wordDict, 0);
        return ans;
    }
};
