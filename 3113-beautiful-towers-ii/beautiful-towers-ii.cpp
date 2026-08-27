class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> right(n, 0);
        stack<pair<int, int>> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top().first>maxHeights[i]){
                right[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({maxHeights[i], i});
        }
        while(!st.empty()){
            right[st.top().second] = n - st.top().second;
            st.pop();
        }

        for(int i=n-1; i>=0; i--){
            long long extra = (i+right[i]<n) ? right[i+right[i]] : 0;
            long long curr = maxHeights[i]*right[i] + extra;
            right[i] = curr;
        }

        vector<long long> left(n, 0);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first>maxHeights[i]){
                left[st.top().second] = st.top().second - i;
                st.pop();
            }
            st.push({maxHeights[i], i});
        }
        while(!st.empty()){
            left[st.top().second] = st.top().second + 1;
            st.pop();
        }

        for(int i=0; i<n; i++){
            long long extra = (i-left[i]>=0) ? left[i-left[i]] : 0;
            long long curr = maxHeights[i]*left[i] + extra;
            left[i] = curr;
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, left[i] + right[i] - maxHeights[i]);
        }
        return ans;
    }
};