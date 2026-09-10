class Solution {
public:
    bool check(vector<int>& nums, int k, int m){
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=m){
                count++;
                i++;
            }
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
       int l = INT_MAX;
       int r = INT_MIN;
       for(int n: nums){
        l = min(n, l);
        r = max(n, r);
       }
       int ans = r;
       while(l<=r){
        int m = l + (r - l) / 2;
        if(check(nums, k, m)){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
       }
       return ans;
       
    }
};