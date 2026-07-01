class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> prefix(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        int l = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
            if(count[nums[i]]>1){
                while(nums[l]!=nums[i]){
                    count[nums[l]]--;
                    l++;
                }
                count[nums[l]]--;
                l++;
            }
            ans = max(ans, prefix[i+1] - prefix[l]);
        }
        return ans;
    }
};