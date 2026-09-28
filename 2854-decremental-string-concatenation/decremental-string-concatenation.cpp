class Solution {
public:
    vector<vector<vector<int>>> memo;
    int terms(vector<string>& words, int start, int end, int i){
        if(i==words.size()) return 0;
        if(memo[start][end][i]!=-1) return memo[start][end][i];
        int ans = INT_MAX;
        int n = words[i].size();
        int s = words[i][0]-'a';
        int e = words[i][n-1]-'a';

        if(start==e) ans = min(ans, n-1 + terms(words, s, end, i+1));
        else ans = min(ans, n + terms(words, s, end, i+1));

        if(end==s) ans = min(ans, n-1 + terms(words, start, e, i+1));
        else ans = min(ans, n + terms(words, start, e, i+1));

        return memo[start][end][i] = ans;

    }
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        memo.resize(26, vector<vector<int>>(26, vector<int>(n, -1)));
        int s = words[0][0]-'a';
        int e = words[0].back()-'a';
        return words[0].size() + terms(words, s, e, 1);
    }
};