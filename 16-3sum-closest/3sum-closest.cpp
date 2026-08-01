class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int ans;
        for(int i=0; i<nums.size()-2; i++){
            int search = target - nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                int curr = nums[l] + nums[r];
                if(curr<search){
                    if(diff>search-curr){
                        diff = search - curr;
                        ans = curr + nums[i];
                    }
                    l++;
                }
                else if(curr>search){
                    r--;
                    if(diff>curr - search){
                        diff = curr - search;
                        ans = nums[i] + curr;
                    }
                }
                else return target;
            }
        }
        return ans;
    }
};