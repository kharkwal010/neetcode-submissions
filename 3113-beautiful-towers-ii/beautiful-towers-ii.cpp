class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<int> right(n, 0);
        stack<pair<int, int>> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top().first>maxHeights[i]){
                int top = st.top().second;
                st.pop();
                right[top] = (i - top);
            }
            st.push({maxHeights[i], i});
        }
        while(!st.empty()){
            int top = st.top().second;
            st.pop();
            right[top] = n - top;
        }
        vector<long long> rightsum(n, 0);
        long long sum = 0;
        for(int i=n-1; i>=0; i--){
            long long end = (i + right[i]==n) ? 0 : rightsum[i + right[i]];
            sum = (long long)maxHeights[i]*right[i] + end;
            rightsum[i] = sum;            
        }

        vector<int> left(n, 0);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first>maxHeights[i]){
                int top = st.top().second;
                st.pop();
                left[top] = (top - i);
            }
            st.push({maxHeights[i], i});
        }
        while(!st.empty()){
            int top = st.top().second;
            st.pop();
            left[top] = 1 + top;
        }
        vector<long long> leftsum(n, 0);
        sum = 0;
        for(int i=0; i<n; i++){
            long long end = (i - left[i]==-1) ? 0 : leftsum[i - left[i]];
            sum = (long long)maxHeights[i]*left[i] + end;
            leftsum[i] = sum;
            
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, leftsum[i] + rightsum[i] - maxHeights[i]);
            // cout<<maxHeights[i]<<" "<< leftsum[i]<<" "<<rightsum[i]<<endl;
        }
        return ans;

    }
};