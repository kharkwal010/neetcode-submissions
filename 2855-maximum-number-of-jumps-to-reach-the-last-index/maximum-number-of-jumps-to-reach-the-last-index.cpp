class Solution {
public:
    vector<int> memo;
    int jumps(vector<vector<int>>& adj, int i){
        if(i==adj.size()-1) return 0;
        if(memo[i]!=-1) return memo[i];
        int ans = INT_MIN;
        for(int nei: adj[i]){
            ans = max(ans, 1 + jumps(adj, nei));
        }
        return memo[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(abs(nums[i]-nums[j])<=target) adj[i].push_back(j);
            }
        }
        memo.resize(n, -1);
        int ans = jumps(adj, 0);
        if(ans<0) return -1;
        return ans;
    }
};