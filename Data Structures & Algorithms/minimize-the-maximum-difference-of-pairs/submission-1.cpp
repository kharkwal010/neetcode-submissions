class Solution {
public:
    bool check(vector<int>& nums, int p, int m){
        int count = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-nums[i-1]<=m){
                i++;
                count++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.back() - nums[0];
        while(r>l){
            int m = (r+l)/2;
            if(check(nums, p, m)) r = m;
            else l = m+1;
        }
        return l;

    }
};