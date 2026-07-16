class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        stack<pair<int, int>> st;
        for(int i=0; i<prices.size(); i++){
                while(!st.empty() && st.top().first>=prices[i]){
                    ans[st.top().second] = st.top().first - prices[i];
                    st.pop();
                }
                st.push({prices[i], i});
        }
        return ans;
    }
};