class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int i=1; i<nums.size(); i++){
            nums[i]=nums[i]+nums[i-1];
        }
        int ans= 0;
        count[0]++;
        for(int i=0; i<nums.size(); i++){
            if(count.find(nums[i]-k)!=count.end()){
                ans = ans + count[nums[i]-k];
            }
            count[nums[i]]++;
        }
        
        return ans;
    }
};