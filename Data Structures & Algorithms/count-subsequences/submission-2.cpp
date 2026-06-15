class Solution {
public:
    unordered_map<string, int> memo;
    int dis(string s, string t, int i, int j){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        string key = to_string(i) + "," + to_string(j);
        if(memo.find(key)!=memo.end()) return memo[key];
        int pick = 0;
        if(i<s.size() && j<t.size() && s[i]==t[j]){
            pick = dis(s, t, i+1, j+1);
        }
        int leave = dis(s, t, i+1, j);
        memo[key] = pick + leave;
        return memo[key];
    }

    int numDistinct(string s, string t) {
        if(t.size()>s.size()) return 0;
        return dis(s, t, 0, 0);
    }
};
