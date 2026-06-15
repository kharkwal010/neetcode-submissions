class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> memo;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<nums.size()-1 ; i++){

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
                    vector<int> element = {nums[i], nums[start], nums[end]};
                    if(memo.find(element)==memo.end()){
                        ans.push_back(element);
                        memo.insert(element);                        
                    }
                    start++;
                    end--;
                }
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1]){
                i++;
            }

        }
        return ans;         
    }
};
