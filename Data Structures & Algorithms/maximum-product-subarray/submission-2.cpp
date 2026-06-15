class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[nums.size()-1];
        int mini = nums[nums.size()-1];
        int ans = max(maxi, mini);
       for(int i = nums.size()-2; i>=0;  i--){
            int temp = maxi;
            maxi = max(nums[i], max(maxi*nums[i], mini*nums[i]));
            mini = min(nums[i], min(temp*nums[i], mini*nums[i]));
            ans = max(maxi, ans);
       }
       return ans;
    }
};
