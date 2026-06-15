class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool one_zero = false;
        bool more_zero = false;
        int product= 1;
        int loc_zero = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                if(one_zero){
                    more_zero = true;
                    break;
                }
                else{
                    one_zero = true;
                    loc_zero = i;
                    continue;
                }
            }
            product = product * nums[i];
        }
        vector<int> ans(nums.size(), 0);
        if(more_zero) return ans;
        if(one_zero){
            ans[loc_zero] = product;
            return ans;
        }
        for(int i=0; i<nums.size(); i++){
            ans[i]=(product/nums[i]);
        }
        return ans;
        

    }
};
