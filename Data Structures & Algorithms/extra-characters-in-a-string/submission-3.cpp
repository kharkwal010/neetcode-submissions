class Solution {
public:
    unordered_map<int, int> memo;
    unordered_set<string> present;
    int dp(string s, int i){
        if(i==s.size()) return 0;
        if(memo.count(i)) return memo[i];
        int ans = INT_MAX;
        for(int j=1; j<s.size(); j++){
            if(i+j>s.size()) break;
            string sub = s.substr(i, j);
            if(present.count(sub)){
                ans = min(ans, dp(s, i+sub.size()));
            }
        }
        ans = min(ans, 1+dp(s, i+1));
        memo[i] = ans;
        return ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(string st: dictionary){
            present.insert(st);
        }
        return dp(s, 0);
    }
};