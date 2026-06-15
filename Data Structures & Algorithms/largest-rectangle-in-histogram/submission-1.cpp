class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right(heights.size(),0);
        vector<int> left(heights.size(),0);
        stack<pair<int,int>> stack1;
        for(int i=0; i<heights.size(); i++){
            while(!stack1.empty() && stack1.top().first>=heights[i]){
                auto top = stack1.top();
                stack1.pop();
                left[i]=i-top.second + left[top.second];
            }
            stack1.push({heights[i],i});
        }

        //repeat again:
        stack<pair<int, int>> stack2;
        for(int i=heights.size()-1; i>=0; i--){
            while(!stack2.empty() && stack2.top().first>=heights[i]){
                auto top = stack2.top();
                stack2.pop();
                right[i]=top.second - i + right[top.second];
            }
            stack2.push({heights[i],i});
        }

        int ans = 0;
        for(int i=0; i<heights.size(); i++){
            ans = max((right[i]+left[i]+1)*heights[i], ans);
        }
        return ans;
    }
};
