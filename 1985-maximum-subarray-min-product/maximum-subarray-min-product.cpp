class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        for(int i=0; i<n; i++) prefix[i+1] = prefix[i] + nums[i];
        vector<long long> left(n, 0);
        vector<long long> right(n, 0);
        stack<pair<int, int>> st;
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && st.top().first>nums[i]){
                int j = st.top().second;
                left[j] = prefix[i] - prefix[j];
                st.pop();
            }
            st.push({nums[i], i});
        }
        while(!st.empty()){
            int j = st.top().second;
            left[j] = prefix[n] - prefix[j];
            st.pop();
        }

        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && st.top().first>nums[i]){
                int j = st.top().second;
                right[j] = prefix[j] - prefix[i+1];
                st.pop();
            }
            st.push({nums[i], i});
        }
        while(!st.empty()){
            int j = st.top().second;
            right[j] = prefix[j] - prefix[0];
            st.pop();
        }

        for(int ele: right) cout<<ele<<" ";

        long long ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, nums[i]* (left[i] + right[i]));
        }
        int mod = 1e9 + 7;
        return ans%mod;

    }
};