class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                int j = i+1;
                while(j<nums.size()){
                    if(nums[j]<=nums[i]) break;
                    j++;
                }
                swap(nums[i], nums[j-1]);
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};