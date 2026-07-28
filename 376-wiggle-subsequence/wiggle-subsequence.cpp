class Solution {
public:
    int check(vector<int>& nums, int currval, bool asc){
        int curr = 1;
        for(int i=1; i<nums.size(); i++){
            if(asc){
                if(nums[i]>currval){
                    curr++;
                    asc = false;
                    currval = nums[i];
                }
                currval = min(currval, nums[i]);
            }
            else{
                if(nums[i]<currval){
                    curr++;
                    asc = true;
                    currval = nums[i];
                }
                currval = max(currval, nums[i]);
            }
            
        }
        return curr;
    }
    int wiggleMaxLength(vector<int>& nums) {
        int curr = max(check(nums, nums[0], true), check(nums, nums[0], false));
        return curr;
    }
};