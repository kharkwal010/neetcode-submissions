class Solution {
public:
    unordered_map <int, bool> memo;
    bool dfs (string s, vector<string>& wordDict, int i){
        if (memo.find(i)!=memo.end()){
            return memo[i];
        }
        if (i==s.size()){
            return true;
        }
        for (string words : wordDict){
            if (s.substr(i, words.size())==words){
                if(dfs(s, wordDict, i+words.size())){
                    memo[i]=true;
                    return true;
                }
            }
        }
        memo[i]=false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs (s, wordDict, 0);
    }
};
