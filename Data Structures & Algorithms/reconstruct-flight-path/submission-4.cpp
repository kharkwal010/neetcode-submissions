class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for(auto& ele: tickets){
            adj[ele[0]].push_back(ele[1]);
        }
        for(auto& ele: adj){
            sort(ele.second.rbegin(), ele.second.rend());
        }
        stack<string> st;
        vector<string> ans;
        st.push("JFK");
        while(!st.empty()){
            string top = st.top();
            if(adj[top].size()==0){
                ans.push_back(top);
                st.pop();
            }
            else{
                st.push(adj[top].back());
                adj[top].pop_back();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
