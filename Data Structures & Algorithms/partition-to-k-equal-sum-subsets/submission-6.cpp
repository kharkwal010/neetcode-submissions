class Solution {
public:
    bool check(vector<int>& nums, int i, vector<int>& sums, int target){
        if(i==nums.size()){
            for(int s: sums) if(s!=target) return false;
            return true;
        }
        bool ans = false;
        for(int j=0; j<sums.size(); j++){
            if(sums[j]+nums[i]>target) continue;
            if(j > 0 && sums[j] == sums[j-1]) continue;
            sums[j] += nums[i];
            ans = ans || check(nums, i+1, sums, target);
            sums[j] -= nums[i];
        }
        return ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int n: nums){
            sum += n;
        }
        sort(nums.rbegin(), nums.rend());
        if(sum%k!=0) return false;
        int target = sum/k;
        vector<int> sums(k,0);
        return check(nums, 0, sums, target);
    }
};