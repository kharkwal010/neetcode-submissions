class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<long long> prefix(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        unordered_map<int, int> terms;
        int i=0;
        while(i<k){
            terms[nums[i]]++;
            i++;
        }
        long long ans = (terms.size()==k) ? prefix[k] - prefix[0] : 0;
        int l = 0;
        while(i<nums.size()){
            terms[nums[i]]++;
            i++;
            terms[nums[l]]--;
            if(terms[nums[l]]==0) terms.erase(nums[l]);
            l++;
            if(terms.size()==k) ans = max(ans, prefix[i]-prefix[l]);
        }
        return ans;
    }
};