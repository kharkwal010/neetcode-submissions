class Solution {
public:
    unordered_map<int, int> memo;
    int dp(string s, vector<string>& dict, int i){
        if(i==s.size()) return 0;
        if(memo.count(i)) return memo[i];
        int ans = INT_MAX;
        for(string ele: dict){
            string sub;
            if(i+ele.size()<=s.size()) sub = s.substr(i, ele.size());
            if(sub==ele){
                ans = min(ans, dp(s, dict, i+ele.size()));
            }
        }
        ans = min(ans, 1+dp(s, dict, i+1));
        memo[i] = ans;
        return ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        return dp(s, dictionary, 0);
    }
};