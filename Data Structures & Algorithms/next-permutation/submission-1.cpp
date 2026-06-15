class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int maxi  = nums[n-1];
        int next = 0;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<maxi){
                int j = i+1;
                for(int k=j; k<nums.size(); k++){
                    if(nums[k]<nums[j] && nums[k]>nums[i]) j = k;
                }
                swap(nums[j], nums[i]);
                next = i+1;
                break;
            }
            maxi = max(maxi, nums[i]);
        }
        reverse(nums.begin()+next, nums.end());
        return;
    }
};