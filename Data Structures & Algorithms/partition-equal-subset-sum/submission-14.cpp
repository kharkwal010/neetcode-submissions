class Solution {
public: 
    unordered_map<string, bool> memo;
    bool check(vector<int> nums, int target, int a){
        if(target==0){
            return true;
        }
        if(a>=nums.size()){
            return false;
        }
        string key = to_string(target)+"+"+to_string(a);
        if(memo.find(key)!=memo.end()){
            return memo[key];
        }        
        memo[key]=check(nums, target-nums[a], a+1) || check(nums, target, a+1);
        return memo[key];
        
               
    }
   
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i= 0; i<nums.size(); i++){
            sum= sum + nums[i];
        }   
        if (sum%2!=0){
            return false;
        }
        else{
            sum = sum/2;
        }
        return check(nums, sum, 0);

    }
};
