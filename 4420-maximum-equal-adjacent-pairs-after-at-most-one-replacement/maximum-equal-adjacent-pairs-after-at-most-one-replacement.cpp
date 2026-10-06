class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int count = 0;
        int match = 0;
        map<pair<int, int>, int> pairs; 
        for(int i=0; i<nums.size()-1; i++){
            int a = min(nums[i], nums[i+1]);
            int b = max(nums[i], nums[i+1]);
            pairs[{a, b}]++;
            if(nums[i]==nums[i+1]) count++;
            else match = max(match, pairs[{a, b}]);            
        }
        return count + match;

    }
};