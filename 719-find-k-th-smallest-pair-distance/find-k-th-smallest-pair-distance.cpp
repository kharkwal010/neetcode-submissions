class Solution {
public:
    bool greater(vector<int>& nums, int k, int m){
        int i=0;
        int j=1;
        int n = nums.size();
        int count = 0;
        while(j<nums.size()){
            if(nums[j]-nums[i]<=m){
                count += (j-i);
                j++;
            }
            else{
                i++;
                if(i==j) j++;
            }
        }
        return count>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int r = nums[n-1] - nums[0];
        int l = 0;
        int ans = r;
        while(l<=r){
            int m = (l + (r - l) / 2);
            if(greater(nums, k, m)){
                r = m-1;
            }
            else{
                l=m+1;
            }
        }
        return l;


    }
};