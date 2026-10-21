class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        vector<int> prefix(nums.size()+1);
        prefix[0] = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<k) prefix[i+1] = -1;
            else if(nums[i]>k) prefix[i+1] = 1;
            else prefix[i+1] = 0;
        }
        int i = 1;
        unordered_map<int, int> mp;
        mp[0] = 1;
        while(prefix[i]!=0){
            prefix[i] += prefix[i-1];
            mp[prefix[i]]++;
            i++;
        }
        int ans = 0;
        while(i<prefix.size()){
            prefix[i] += prefix[i-1];
            int zero = prefix[i];
            int one = prefix[i]-1;
            ans += mp[zero] + mp[one];
            i++;
        }
        return ans;
        
    }
};