class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<32; i++){
            int term = 0;
            for(int j=0; j<nums.size(); j++){
                term += (nums[j]>>i & 1);
            }
            term = term%3;
            ans =  ans | term<<i;
        }
        return ans;
    }
};