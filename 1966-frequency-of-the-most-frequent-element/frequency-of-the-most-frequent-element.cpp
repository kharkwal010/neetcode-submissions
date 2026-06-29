class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<long long> prefix(nums.size() + 1, 0);
        for(int i=1; i<prefix.size(); i++) prefix[i] = prefix[i-1] + nums[i-1];
        int curr = 1;
        for(int i=nums.size(); i>=0; i--){
            if(i - curr < 0) break;
            while(i - curr - 1 >=0){
                long long status = (long long)nums[i-1]*(curr+1) - (prefix[i] - prefix[i - curr - 1]);
                if(status<=k){
                    curr = curr + 1;
                }
                else break;
            }
        }
        return curr;
    }
};