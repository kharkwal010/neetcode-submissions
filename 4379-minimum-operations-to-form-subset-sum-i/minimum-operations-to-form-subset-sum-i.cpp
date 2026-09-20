class Solution {
public:
    vector<vector<int>> memo;
    int inf = 1e5;
    int dp(vector<vector<pair<int, int>>>& terms, int sum, int i){
        if(sum==0) return 0;
        if(i==terms.size()) return inf;
        if(memo[i][sum]!=-1) return memo[i][sum];
        int ans = inf;
        ans = min(ans, dp(terms, sum, i+1));
        for(int j=0; j<terms[i].size(); j++){
            if(terms[i][j].first>sum) break;
            ans = min(ans, terms[i][j].second + dp(terms, sum - terms[i][j].first, i+1));
        }
        return memo[i][sum] = ans;        

    }
    int minOperations(vector<int>& nums, int sum) {
        vector<vector<pair<int, int>>> terms(nums.size());
        for(int i=0; i<nums.size(); i++){
            int count = 0;
            int n = nums[i];
            while(n>sum){
                n = n/2;
                count++;
            }
            while(n>0){
                terms[i].push_back({n, count});
                n = n/2;
                count++;
            }
            n = nums[i]*2;
            count = 1;
            while(n<=sum){
                terms[i].push_back({n, count});
                count++;
                n=n*2;
            }
            sort(terms[i].begin(), terms[i].end());
            
        }

        int n = nums.size();
        memo.assign(n, vector<int>(sum+1, -1));
        int ans = dp(terms, sum, 0);
        return (ans==inf) ? -1 : ans;
    }
};