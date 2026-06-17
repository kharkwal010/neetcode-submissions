class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int lfar = 0;
        int lnear = 0;
        int ans = 0;
        for(int r=0; r<nums.size(); r++){
            cnt[nums[r]]++;
            if(cnt.size()>k){
                cnt.erase(nums[lnear]);
                lfar = lnear + 1;
                lnear = lfar;
            }
            if(cnt.size()==k){
                while(cnt[nums[lnear]]>1){
                    cnt[nums[lnear]]--;
                    lnear++;
                }
                ans += (lnear-lfar+1);
            }
        }
        return ans;

    }
};