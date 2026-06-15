class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right(heights.size(),0);
        vector<int> left(heights.size(),0);
        stack<pair<int, int>> st;

        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && st.top().first>heights[i]){
                int idx = st.top().second;
                right[idx] = i - idx;
                st.pop();
            }
            st.push({heights[i], i});
        }
        while(!st.empty()){
            int idx = st.top().second;
            right[idx] = heights.size() - idx;
            st.pop();
        }

        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && st.top().first>heights[i]){
                int idx = st.top().second;
                left[idx] = idx - i;
                st.pop();
            }
            st.push({heights[i], i});
        }
        while(!st.empty()){
            int idx = st.top().second;
            left[idx] = idx +1 ;
            st.pop();
        }

        int ans = 0;
        for(int i=0; i<heights.size(); i++){
            ans = max((right[i]+left[i]-1)*heights[i], ans);
        }
        return ans;
    }
};
