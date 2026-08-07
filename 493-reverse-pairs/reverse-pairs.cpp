class Solution {
public:
    vector<int> merge(vector<int>& nums, int l, int r, int& count){
        if(l==r) return {nums[l]};
        int m = (l+r) / 2;
        vector<int> left = merge(nums, l, m, count);
        vector<int> right = merge(nums, m+1, r, count);
        int lf = 0;
        int rg = 0;
        vector<int> ans;
        int i = 0;
        int j = 0;
        for(int j=0; j<right.size(); j++){
            long long tar = (long long)right[j]*2;
            while(i<left.size() && left[i]<=tar){
                i++;
            }
            if(i==left.size()) break;
            count+=(left.size()-i);
        }
        while(lf<left.size() || rg<right.size()){
            if(lf==left.size()){
                ans.push_back(right[rg]);
                rg++;
            }
            else if(rg==right.size()){
                ans.push_back(left[lf]);
                lf++;
            }
            else{
                if(right[rg]<=left[lf]){
                    ans.push_back(right[rg]);
                    rg++;
                }
                else{
                    ans.push_back(left[lf]);
                    lf++;
                }
            }
        }
        return ans;

    }
    int reversePairs(vector<int>& nums) {
        int count = 0;
        merge(nums, 0, nums.size()-1, count);
        return count;
    }
};