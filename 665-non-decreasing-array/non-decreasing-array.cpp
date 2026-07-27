class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
       bool leave = true;
       for(int i=0; i<nums.size()-1; i++){
        if(nums[i]>nums[i+1]){
            if(leave) leave = false;
            else return false;
            if(i==0 || nums[i-1]<=nums[i+1]){
                nums[i] = nums[i+1];
            }
            else nums[i+1] = nums[i];
        }
       }
       return true;
    }
};