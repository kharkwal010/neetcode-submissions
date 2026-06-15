class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      bool zero = false;
      bool more = false;
      int loc = INT_MAX;
      int product = 1;
      for (int i=0; i<nums.size(); i++){
        if(nums[i]==0){
            if(zero==true){
                more = true;
                break;
            }
            zero = true;
            loc = i;
            continue;
        }
        product = product * nums[i];
      }
      vector<int> ans(nums.size(),0);
      if(more==true){
        return ans;
      }
      else if(zero==true){
        ans[loc]=product;
        return ans;
      }
      else{
        for(int i=0; i<nums.size(); i++){
            ans[i]=product / nums[i];
        }
        return ans;
      }
    }

};
