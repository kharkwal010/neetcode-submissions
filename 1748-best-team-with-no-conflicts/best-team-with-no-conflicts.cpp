class Solution {
public:
    vector<vector<int>> memo;
    int score(vector<pair<int, int>>& terms, int i, int prev){
        if(i==terms.size()) return 0;
        if(memo[i][prev]!=-1) return memo[i][prev];
        int ans = 0;
        ans = max(ans, score(terms, i+1, prev));
        // cout<<prev<<endl;
        if(prev==terms.size() || terms[prev].first==terms[i].first || terms[prev].second<=terms[i].second){
            ans = max(ans, terms[i].second + score(terms, i+1, i));
        }
        return memo[i][prev] = ans;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
       vector<pair<int, int>> terms;
       int n = scores.size();
        for(int i=0; i<scores.size(); i++) terms.push_back({ages[i], scores[i]});
        sort(terms.begin(), terms.end());
        memo.resize(n, vector<int>(n+1, -1));
        return score(terms, 0, n);

        
    }
};