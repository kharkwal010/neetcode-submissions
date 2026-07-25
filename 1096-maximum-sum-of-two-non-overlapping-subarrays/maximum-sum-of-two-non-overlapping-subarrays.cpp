class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int prev_max = INT_MIN;
        vector<int> prefix(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        int ans = INT_MIN;
        for(int i = firstLen + secondLen; i<=nums.size(); i++){
            prev_max = max(prev_max, prefix[i-secondLen] - prefix[i-firstLen-secondLen]);
            int curr = prefix[i] - prefix[i-secondLen];
            ans = max(ans, prev_max + curr);
        }
        prev_max = INT_MIN;
        for(int i = firstLen + secondLen; i<=nums.size(); i++){
            prev_max = max(prev_max, prefix[i-firstLen] - prefix[i-firstLen-secondLen]);
            int curr = prefix[i] - prefix[i-firstLen];
            ans = max(ans, prev_max + curr);
        }
        return ans;
    }
};