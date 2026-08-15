class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        bool neg = false;
        int far = 0;
        int near = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                neg = false;
                far = i+1;
                near = i+1;
            }
            else if(nums[i]<0){
                neg = !neg;
                if(neg){
                    if(far==near) near = i+1;
                    ans = max(ans, i-near+1);
                }
                else{
                    ans = max(ans, i - far + 1);
                }
            }
            else{
                if(!neg) ans = max(ans, i - far + 1);
                else ans = max(ans, i-near+1);
            }
        }
        return ans;
    }
};