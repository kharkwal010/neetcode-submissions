class Solution {
public:
    int sol(vector<int>& nums, int last , int first) {
        int one = nums[first -1];
        int two = 0;
        int leave =  nums[first -2];
        int curr;
        for (int i =first -3; i>=last; i--){
            curr = nums [i];
            curr = max(curr+one, curr + two);
            two = one;
            one = leave;
            leave = curr;
        }
        
        return max (leave, one);

    }
    int rob(vector<int>& nums) {
        vector<int> dp1 =nums;
        if(nums.size()==1){
            return nums[0];
        }
        int one = sol(dp1, 1, nums.size());
        vector<int> dp2 = nums;
        int two = sol(dp2, 0, nums.size()-1);
        return max(one, two);
        
        
        
    }
};
