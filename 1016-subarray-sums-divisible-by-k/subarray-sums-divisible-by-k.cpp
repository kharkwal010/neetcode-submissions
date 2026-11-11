class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        long long sum = 0;
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int ans = 0;
        for(int n: nums){
            sum += n;
            int rem = (k + sum%k) % k;
            ans += prefix[rem];
            prefix[rem]++;
        }
        return ans;
    }
};