class Solution {
public:
    vector<int> memo;
    long long days(int n, vector<pair<int, int>>& terms){
        if(n==0) return 0;
        if(n<0) return INT_MAX;
        if(memo[n]!=-1) return memo[n];
        long long ans = INT_MAX;
        for(int i=0; i<terms.size(); i++){
            ans = min(ans, 1 + terms[i].second + days(n - terms[i].first, terms));
        }
        return memo[n] = ans;
    }
    int minDays(int n) {
        vector<pair<int, int>> terms;
        int curr = 0;
        int j = 1;
        while(curr + j<=n){
            curr = curr + j;
            terms.push_back({curr, j});
            j++;
        }
        int t = terms.size();
        memo.resize(n+1, -1);
        return days(n, terms) - 1;


    }
};