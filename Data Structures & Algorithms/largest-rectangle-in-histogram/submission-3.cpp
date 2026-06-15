class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> bright(heights.size(),0);
        vector<int> bleft(heights.size(),0);
        stack<pair<int, int>> st;
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && st.top().first>heights[i]){
                auto top = st.top();
                st.pop();
                bright[top.second] = i - top.second - 1;
            }
            st.push({heights[i], i});            
        }
        while(!st.empty()){
                auto top = st.top();
                st.pop();
                bright[top.second] = heights.size() - top.second - 1;
        }

        //copy pasted and made some changes:
        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && st.top().first>heights[i]){
                auto top = st.top();
                st.pop();
                bleft[top.second] = top.second - i - 1;
            }
            st.push({heights[i], i});            
        }
        while(!st.empty()){
                auto top = st.top();
                st.pop();
                bleft[top.second] = top.second;
        }

        int largest = 0;
        for(int i=0; i<heights.size(); i++){
            largest = max(largest, (bleft[i]+bright[i]+1)*heights[i]);
        }
        return largest;
    }
};
