class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long> terms;
        int mod = 1e9+7;
        long long dis = d;
        for(int i=0; i<nums.size(); i++){
            if(s[i]=='R') terms.push_back(nums[i] + dis);
            else terms.push_back(nums[i]-dis);
        }
        sort(terms.begin(), terms.end());
        long long ans = 0;
        int n = nums.size();
        for(int i=0; i<nums.size()-1; i++){
            long long dist = (terms[i+1] - terms[i]) % mod;
            ans = (ans + 1LL*(i+1) * (n-i-1) * dist) % mod;
        }
        return ans;
        
    }
};