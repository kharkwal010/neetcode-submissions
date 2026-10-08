class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefix;
        int mx = INT_MIN;
        for(int n: nums){
            mx = max(n, mx);
            prefix.push_back(gcd(mx, n));
        }
        sort(prefix.begin(), prefix.end());
        // for(int p: prefix) cout<<p<<" ";
        int l=0;
        int r = nums.size()-1;
        long long ans = 0;
        while(l<r){
            ans += gcd(prefix[l], prefix[r]);
            l++;
            r--;
        }
        return ans;
    }
};