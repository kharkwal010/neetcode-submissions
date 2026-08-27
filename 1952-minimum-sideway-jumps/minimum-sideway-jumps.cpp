class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<int>& obstacles, int i, int lane){
        if(i==obstacles.size()-1) return 0;
        if(memo[i][lane]!=-1) return memo[i][lane];
        int ans = INT_MAX;
        if(obstacles[i+1]==lane){
            for(int j=1; j<=3; j++){
                if(j==lane) continue;
                if(obstacles[i]!=j) ans = min(ans, 1+dp(obstacles, i, j));
            }
        }
        else ans = min(ans, dp(obstacles, i+1, lane));
        return memo[i][lane] = ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        memo.resize(n, vector<int>(4, -1));
        int ans = dp(obstacles, 0, 2);
        return (ans==INT_MAX) ? 0 :ans;

    }
};