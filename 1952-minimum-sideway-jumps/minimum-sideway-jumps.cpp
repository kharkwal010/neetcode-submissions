class Solution {
public:
    vector<vector<int>> memo;
    int jump(vector<int>& obstacles, int i, int lane){
        if(i==obstacles.size()-1) return 0;
        if(memo[i][lane]!=-1) return memo[i][lane];
        int ans = INT_MAX;
        if(obstacles[i+1]-1==lane){
            int above = (lane+3-1)%3;
            int down = (lane+3+1)%3;
            if(obstacles[i]-1!=above) ans = min(ans, 1+jump(obstacles, i+1, above));
            if(obstacles[i]-1!=down) ans = min(ans, 1+jump(obstacles, i+1, down));
        }
        else ans = min(ans, jump(obstacles, i+1, lane));
        return memo[i][lane]=ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        memo.resize(n, vector<int>(3, -1));
        return jump(obstacles, 0, 1);
    }
};