class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<int>& job, int d, int i){
        if(d==1) return memo[i][d] = *max_element(job.begin()+i, job.end());
        if(memo[i][d]!=-1) return memo[i][d];
        int maxi = 0;
        int ans = INT_MAX;
        for(int j=i; j<=job.size()-d; j++){
            maxi = max(job[j], maxi);
            ans = min(ans, maxi + dp(job, d-1, j+1));
        }
        return memo[i][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        memo.resize(n, vector<int>(d+1, -1));
        if(n<d) return -1;
        return dp(jobDifficulty, d, 0);
    }
};