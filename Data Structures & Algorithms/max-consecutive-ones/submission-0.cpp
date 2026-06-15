class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int prev = 0;
        for(int n: nums){
            if(n==0) prev = 0;
            else prev++;
            ans = max(ans, prev);
        }
        return ans;
    }
};