class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
       vector<int> right(nums.size());
       vector<int> left(nums.size());
       int n = nums.size();
       stack<pair<int, int>> st;
       for(int i=0; i<n; i++){
        while(!st.empty() && st.top().first>nums[i]){
            int j = st.top().second;
            right[j] = i - j;
            st.pop();
        }
        st.push({nums[i], i});
       }
       while(!st.empty()){
            int j = st.top().second;
            right[j] = n - j;
            st.pop();
       }

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first>nums[i]){
                int j = st.top().second;
                left[j] = j - i;
                st.pop();
            }
            st.push({nums[i], i});
       }
       while(!st.empty()){
            int j = st.top().second;
            left[j] = j + 1;
            st.pop();
       }

        int ans = 0;
       for(int i=0; i<=k; i++){
            if(i + right[i]<=k) continue;
            ans = max(ans, nums[i]*(right[i]+left[i]-1));
       }
       for(int i=k+1; i<n; i++){
        if(i-left[i]>=k) continue;
        ans = max(ans, nums[i] * (right[i]+ left[i] - 1));
       }
       return ans;
    }
};