class Solution {
public:
    bool check(vector<int>& nums, int target){
        long long remaining = 0;
        for(int i=0; i<nums.size(); i++){
            remaining += (target - nums[i]);
            if(remaining<0) return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int r = *max_element(nums.begin(), nums.end());
        int l = *min_element(nums.begin(), nums.end());
        while(l<=r){
            int m = r - (r-l)/2;
            // cout<<m<<endl;
            if(check(nums, m)) r = m-1;
            else l = m+1;
            // cout<<l<<" "<<r<<endl;
        }
        return l;
    }
};