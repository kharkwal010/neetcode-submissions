class Solution {
public:
    int rob(vector<int>& nums) {
        int two = 0;
        int one = nums[nums.size()-1];
        int leave = nums[nums.size()-2];
        

        for (int i = nums.size()-3; i>=0; i--){
            int temp = leave;
            leave = max (nums[i]+one, nums[i]+two);
            two = one;
            one = temp;
            
        }
        return max(leave, one);

        
    }
};
