class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long prefix = 0;
        for(int n: nums) prefix += n;
        int rem = prefix%p;
        if(rem==0) return 0;

        unordered_map<int, int> index;
        index[0] = -1;
        prefix = 0;
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            prefix += nums[i];
            int term = prefix%p;
            int search = (term + p - rem)%p;
            if(index.count(search)) ans = min(ans, i-index[search]);
            index[term] = i;
        }
        if(ans==nums.size()) return -1;
        return ans;
    }
};