class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        bool count = false;
        int j = 0;
        int tar = *max_element(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==tar){
                k--;
                if(k<=0){
                    count = true;
                    while(nums[j]!=tar) j++;
                    j++;
                }
            }
            if(count) ans += (j);
        }
        return ans;
    }
};