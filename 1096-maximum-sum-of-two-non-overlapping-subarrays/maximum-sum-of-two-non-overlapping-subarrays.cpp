class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

        vector<int> prefix(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++) prefix[i+1] = prefix[i] + nums[i];
        // one first;
        int ans = 0;
        int maxi= prefix[firstLen] - prefix[0];
        for(int i= firstLen + secondLen; i<prefix.size(); i++){
            maxi = max(maxi, prefix[i-secondLen] - prefix[i-secondLen-firstLen]);
            ans = max(ans, prefix[i] - prefix[i-secondLen] + maxi);
        }
        // cout<<ans<<endl;
        int maxi2 = prefix[secondLen] - prefix[0];
        for(int i= firstLen + secondLen; i<prefix.size(); i++){
            maxi2 = max(maxi2, prefix[i-firstLen] - prefix[i-secondLen-firstLen]);
            ans = max(ans, prefix[i] - prefix[i-firstLen] + maxi2);
        }  
        // cout<<ans<<endl;
        return ans;     

    }
};