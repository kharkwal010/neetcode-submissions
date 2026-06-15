class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> values;
        for (int i=0; i<nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = - nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(right>left){
                int sum = nums[right] + nums [left];
                if (right>left && sum>target){
                    right--;
                }
                if (right>left && sum<target){
                    left++;
                }
                if (sum == target){
                    
                    values.push_back({nums[i], nums[left], nums[right]});
                        // Skip duplicates
    while (left < right && nums[left] == nums[left + 1]) left++;
    while (left < right && nums[right] == nums[right - 1]) right--;
                    right--;
                    left++;
                }
                
            }
          
        }
        return values;
    }
};
