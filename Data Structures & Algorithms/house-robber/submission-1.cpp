class Solution {
public:
    int rob(vector<int>& nums) {
        int two = 0;
        int one = nums[nums.size()-1];
        int leave = nums[nums.size()-2];
        int curr;

        for (int i = nums.size()-3; i>=0; i--){
            curr = nums[i];
            curr = max (curr+one, curr+two);
            two = one;
            one = leave;
            leave = curr;
        }
        return max(leave, one);

        
    }
};
