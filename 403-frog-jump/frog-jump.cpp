class Solution {
public:
    vector<vector<int>> memo;
    bool cross(vector<int>& stones, int i, int prev){
        if(i==stones.size()-1) return true;
        if(memo[i][prev]!=-1) return memo[i][prev];
        bool ans = false;
        int jump;
        if(i==0) jump = 1;
        else jump = stones[i] - stones[prev];
        int j = i+1;
        int tar = stones[i]+jump;
        while(j<stones.size() && stones[j]<=tar+1){
            if(i!=0 && stones[j]==tar-1) ans = ans || cross(stones, j, i);
            if(stones[j]==tar) ans = ans || cross(stones, j, i);
            if(i!=0 && stones[j]==tar+1) ans = ans || cross(stones, j, i);
            j++;
        }
        memo[i][prev] = ans;
        return ans;        
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        memo.resize(n, vector<int>(n, -1));
        return cross(stones, 0, 0);
    }
};