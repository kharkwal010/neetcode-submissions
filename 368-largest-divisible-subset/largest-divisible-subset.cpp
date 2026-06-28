class Solution {
public:
    unordered_map<int, vector<int>> memo;
    vector<int> dp(vector<int>& nums, int i){
        if(i==nums.size()) return {};
        if(memo.count(i)) return memo[i];
        vector<int> res;
        res.push_back(nums[i]);
        for(int j=i+1; j<nums.size(); j++){
            vector<int> temp = {nums[i]};
            if(nums[j]%nums[i]==0){
                vector<int> next = dp(nums, j);
                temp.insert(temp.end(), next.begin(), next.end());
                if(temp.size()>res.size()) res = temp;
            }
                       
        }
        return memo[i] = res;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> temp;
        for(int i=0; i<nums.size(); i++){
            temp = dp(nums, i);
            if(temp.size()>ans.size()) ans = temp;
        }
        return ans;
    }
};