class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int, int>> st;
        int n = nums.size();
        vector<int> ans(nums.size(), -1);
        for(int i=0; i<n*2; i++){
            while(!st.empty() && st.top().first<nums[i%n]){
                auto top = st.top();
                st.pop();
                ans[top.second] = nums[i%n];
            }
            if(i<n) st.push({nums[i], i});
        }
        return ans;
    }
};