class Solution {
public:
    int solve(vector<int>& nums, int k, int m){
        int count = 0;
        int ans = 0;
        for(int n: nums){
            if(n==k) count--;
            else if(n==m) count++;
            if(count<0) count = 0;
            ans = max(ans, count);
        }
        return ans;
    }
    int maxFrequency(vector<int>& nums, int k) {
        unordered_set<int> terms;
        int count = 0;
        for(int n: nums){
            terms.insert(n);
            if(n==k) count++;
        }
        int ans = count;
        for(int n: terms){
            if(n==k) continue;
            ans = max(ans, count + solve(nums, k, n));
        }
        return ans;
    }
};