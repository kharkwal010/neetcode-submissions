class Solution {
public:
    void sets(vector<int>& nums, int& sum, int curr, int i){
        if(i==nums.size()){
            sum += curr;
            return;
        }
        sets(nums, sum, curr, i+1);
        sets(nums, sum, curr^nums[i], i+1);
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        sets(nums, sum, 0, 0);
        return sum;
    }
};