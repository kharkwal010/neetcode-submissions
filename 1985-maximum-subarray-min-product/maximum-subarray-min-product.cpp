class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();
        // this is the simple quesiton of combimatrixs;
        vector<int> right(n , 0);
        vector<int> left(n, 0);
        stack<pair<int, int>> st;
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && st.top().first>nums[i]){
                auto top = st.top();
                st.pop();
                right[top.second] = i - top.second;
            }
            st.push({nums[i], i});
        }
        while(!st.empty()){
            right[st.top().second] = n - st.top().second;
            st.pop();
        }
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first>nums[i]){
                auto top = st.top();
                st.pop();
                left[top.second] = top.second - i;
            }
            st.push({nums[i], i});
        }
        while(!st.empty()){
            left[st.top().second] = st.top().second + 1;
            st.pop();
        }
        vector<long long> prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            long long l = prefix[i+1] - prefix[i + 1 - left[i]];
            long long r = prefix[i + right[i]] - prefix[i + 1];
            ans = max(ans, (l+r)*nums[i]);
        }
        return ans%mod;


    }
};