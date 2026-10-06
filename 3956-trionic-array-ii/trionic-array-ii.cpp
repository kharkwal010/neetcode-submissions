class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
       long long ans = LLONG_MIN;
       bool inc = false;
       bool dec = false;
       int nl = 0;
       int l = 0;
       vector<long long> prefix(nums.size()+1);
       prefix[0] = 0;
       for(int i=0; i<nums.size(); i++){
            prefix[i+1] = prefix[i] + nums[i];
       }

       for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                l = i+1;
                nl = i+1;
                inc = false;
                dec = false;
            }

            else if(nums[i]<nums[i+1]){
                if(dec){
                    ans = max(ans, prefix[i+2] - prefix[l]);
                    if(nl==l) nl = i;
                    else if(nums[nl]<0) nl++;
                }
                else{
                    if(inc && nums[l]<0){
                        l++;
                        if(nl<l) nl = l;
                    }
                    inc = true;
                }
            }
            else{
                if(inc){
                    dec = true;
                    l = nl;
                }
                else{
                    l = i+1;
                    nl = i+1;
                    inc = false;
                    dec = false;
                }
            }
       }
       return ans;



    }
};