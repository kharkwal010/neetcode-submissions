class Solution {
public:
    unordered_map<string, int> memo;
    int coins(vector<int>& nums, int l, int r){
        if(l>r) return 0;
        string key = to_string(l) + "," + to_string(r);
        // if(memo.find(key)!=memo.end()) return memo[key];
        int ans = 0;
        for(int i=l; i<=r; i++){
            ans = max(ans, coins(nums, l, i-1) + nums[l-1] * nums[i] * nums[r+1] + coins(nums, i+1, r));
        }
        memo[key] = ans;
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return coins(nums, 1, nums.size()-2);
    }
};
