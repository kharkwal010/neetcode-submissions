class Solution {
public:
   unordered_map<string, int> memo;
   int comb(vector<int>& nums, int target, int layer, int sum){
    if(layer==nums.size()){
        if(sum==target) return 1;
        else return 0;
    }
    string key = to_string(sum)+"+"+to_string(layer);
    if(memo.find(key)!=memo.end()){
        return memo[key];
    }
    memo[key]= comb(nums, target, layer+1, sum+nums[layer])+comb(nums, target, layer+1, sum-nums[layer]);
    return memo[key];
   }
       
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return comb(nums,target,0,0);
       

    }
};
