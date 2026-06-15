class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }

       int one = nums[nums.size()-1];
       int two = 0;
       int leave = nums[nums.size()-2];
       for(int i=nums.size()-3; i>=0; i--){
        int temp = leave;
        leave = max(one+nums[i], two+nums[i]);
        two = one;
        one = temp;
       }
       return max(leave, one);

        
    }
};
