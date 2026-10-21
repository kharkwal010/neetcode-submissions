class Solution {
public:
    vector<vector<int>> memo;
    int solve(vector<int>& prefix, int i, int picked, int& k){
        if(i>= prefix.size() || picked==3) return 0;
        if(memo[i][picked]!=-1) return memo[i][picked];
        int ans = 0;
        ans = max(ans, solve(prefix, i+1, picked, k));
        ans = max(ans, prefix[i] + solve(prefix, i+k, picked+1, k));
        return memo[i][picked] = ans;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<k; i++) sum += nums[i];
        vector<int> prefix;
        prefix.push_back(sum);
        int l = 0;
        for(int i=k; i<nums.size(); i++){
            sum += nums[i];
            sum -= nums[l];
            l++;
            prefix.push_back(sum);
        }

        memo.resize(prefix.size(), vector<int>(4, -1));
        vector<int> ans;
        int res = solve(prefix, 0, 0, k);
        int picked = 0;
        int i=0;
        while(i<prefix.size()){
            if(picked==3) break;
            if(prefix[i] + solve(prefix, i+k, picked+1, k)==res){
                ans.push_back(i);
                res -= prefix[i];
                i+=k;
                picked++;
            }
            else i++;
        }
        return ans;

    }
};