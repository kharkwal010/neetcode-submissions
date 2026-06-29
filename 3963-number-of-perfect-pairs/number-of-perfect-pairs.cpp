class Solution {
public:

    long long perfectPairs(vector<int>& nums) {
        long long ans = 0; 
        for(int i=0; i<nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 1;
        while(r<nums.size()){
            if(nums[r] - nums[l] <= nums[l]){
                ans += (r - l);
                r++;
            }
            else l++;
            if(l==r) r++;            
        }
        return ans;
    }
};