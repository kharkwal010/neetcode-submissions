class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<nums.size() ; i++){

            int target  = -nums[i];
            int start = i+1;
            int end = nums.size() - 1;

            while(start < end){
                int sum = nums[start] + nums[end];
                if (sum>target){
                    end--;
                }
               else if (sum<target){
                    start++;
                }
                if(sum==target){
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while(start<end && nums[start]==nums[start+1]){
                        start++;
                    }
                    while(start<end && nums[end]==nums[end-1]){
                        end--;
                    }
                    start++;
                    end--;
                }
            }
            while(i<nums.size() && nums[i]==nums[i+1]){
                i++;
            }

        }
        return ans;         
    }
};
