class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mini = INT_MAX;
        stack<pair<int, int>> st;
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && st.top().first<=nums[i]){
                st.pop();                
            }
            if(!st.empty()){
                auto top = st.top();
                if(top.first>nums[i] && top.second<nums[i]) return true;
            }
            mini = min(mini, nums[i]);
            st.push({nums[i], mini});
        }
        return false;
    }
};