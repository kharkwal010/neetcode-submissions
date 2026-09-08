class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int i =  nums.size()-2;
       while(i>=0){
            if(nums[i]<nums[i+1]) break;
            i--;
       } 
       if(i==-1){
            reverse(nums.begin(), nums.end());
            return;
       }

       int j = i+1;
       while(j<nums.size() && nums[j]>nums[i]){
            j++;
       }
    //    cout<<i<<" "<<j<<endl;
        swap(nums[i], nums[j-1]);
       reverse(nums.begin()+i+1, nums.end());
       return;

    }
};