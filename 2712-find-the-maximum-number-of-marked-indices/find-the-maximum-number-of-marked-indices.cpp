class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(), nums.end());
       int k = n/2;
       int i=0;
       int j = k;
       int count = 0;
       while(i<k && j<n){
        if(nums[i]*2<=nums[j]){
            count++;
            i++;
            j++;
        }
        else j++;
       }
       return count*2;
    }
};