class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int end = 0;
        int i = 0;
        while(end<nums.size()-1){
            int prev = end;
            while(i<=prev){
                end = max(end, i+nums[i]);
                i++;
            }
            count++;
        }
        return count;
    }
};
