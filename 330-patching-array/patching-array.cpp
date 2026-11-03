class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0;
        long long currsum = 0;
        int i=0;
        int cnt = 0;
        while(currsum<n){
            if(i<nums.size() && currsum>=nums[i]-1){
                currsum += nums[i];
                i++;
            }
            else{
                cnt++;
                currsum += currsum + 1;
            }    
        }
        return cnt;
    }
};