class Solution {
public:
    vector<int> memo;
    int days(vector<pair<int, int>>& terms, int n){
        if(n==0) return 0;
        if(memo[n]!=-1) return memo[n];
        int ans = INT_MAX;
        for(auto t: terms){
            if(t.first>n) break;
            ans = min(ans, t.second + 1 + days(terms, n - t.first));
        }
        return memo[n] = ans;
    }
    int minDays(int n) {
        vector<pair<int, int>> terms;
        int curr = 1;
        int i = 1;
        while(curr<=n){
            terms.push_back({curr, i});
            i++;
            curr = curr + i;
        }
        // for(auto t: terms){
        //     cout<<t.first<<","<<t.second<<" ";
        // }
        memo.resize(n+1, -1);
        return days(terms, n) - 1;
    }
};