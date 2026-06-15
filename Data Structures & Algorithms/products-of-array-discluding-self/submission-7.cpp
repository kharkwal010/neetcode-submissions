class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int zeros = 0;
       int loc = INT_MAX;
       int prod = 1;
       for(int i=0; i<nums.size(); i++){
        if(nums[i]==0){
            loc = i;
            zeros++;
            continue;
        }
        prod = prod*nums[i];
       }
       vector<int> ans(nums.size(),0);
       if(zeros>1) return ans;
       if(zeros==1) ans[loc]=prod;
       else{
        for(int i=0; i<nums.size(); i++){
            ans[i] = prod / nums[i];
        }
       }
       return ans;

    }
};
