class Solution {
public:
    vector<vector<int>> memo;
    int inf = 1e9;
    long long walls(vector<pair<int, int>>& terms, int i, int n){
        if(n<=0) return 0;
        if(i==terms.size()) return inf;
        if(memo[i][n]!=-1) return memo[i][n];
        long long ans = inf;
        ans = min(ans, walls(terms, i+1, n));
        ans = min(ans, terms[i].first + walls(terms, i+1, n-1-terms[i].second));
        return memo[i][n] = ans;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<pair<int, int>> terms;
        for(int i=0; i<cost.size(); i++){
            terms.push_back({cost[i], time[i]});
        }
        int n = cost.size();
        sort(terms.begin(), terms.end());
        memo.resize(n, vector<int>(n+1, -1));
        return walls(terms, 0, n);
    }
};