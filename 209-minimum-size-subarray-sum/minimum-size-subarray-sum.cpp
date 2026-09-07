class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        queue<pair<long long, int>> q;
        q.push({0, -1});
        int ans = INT_MAX;
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            while(!q.empty() && sum-q.front().first>=target){
                ans = min(ans, i - q.front().second);
                q.pop();
            }
            q.push({sum, i});
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};