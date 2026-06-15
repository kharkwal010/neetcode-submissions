class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        // else if(nums.size()==2) return max(nums[0], nums[1]);
        int one = nums[nums.size()-1];
        int two = 0;
        int leave = nums[nums.size()-2];
        for(int i=nums.size()-3; i>=0; i--){
            int temp = leave;
            leave= nums[i] + max(one, two);
            two = one;
            one = temp;
        }
        return max(leave, one);
    }
};
