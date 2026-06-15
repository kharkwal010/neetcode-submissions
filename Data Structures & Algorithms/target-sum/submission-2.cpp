class Solution {
public:
    map<pair<int, int>, int> memo;
    int comb(vector<int>& nums, int i, int sum, int target){
        if(i==nums.size()){
            if(sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(memo.find({i, sum})!=memo.end()){
            return memo[{i, sum}];
        }
        int add = comb(nums, i+1, sum+nums[i], target);
        int subs = comb(nums, i+1, sum-nums[i], target);
        memo[{i, sum}]= add + subs;
        return add + subs;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return comb(nums, 0, 0, target);
       

    }
};
