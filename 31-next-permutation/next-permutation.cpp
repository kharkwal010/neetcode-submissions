class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n = nums.size()-1;
       for(int i=n-1; i>=0; i--){
        if(nums[i]>=nums[i+1]) continue;
        int nxt = n;
        for(int j = i+1; j<=n; j++){
            if (nums[j]>nums[i]) continue;
            else{
                nxt = j-1;
                break;
            }
        }
            // cout<<i<<" "<<nxt<<endl;
            swap(nums[i], nums[nxt]);
            reverse(nums.begin()+i+1, nums.end());
            return;
       }
       reverse(nums.begin(), nums.end());
       return;

    }
};