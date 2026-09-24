class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[n-1];
        long long count = 0;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<=mini){
                mini = nums[i];
            }
            else{
                int c = ceil((double)nums[i]/mini);
                count += c-1;
                mini = nums[i]/c;
            }
        }
        return count;
    }
};