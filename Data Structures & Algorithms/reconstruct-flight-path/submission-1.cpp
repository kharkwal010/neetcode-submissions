class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for(auto t: tickets){
            adj[t[0]].push_back(t[1]);
        }
        for(auto& it: adj){
            sort(it.second.rbegin(), it.second.rend());
        }

        vector<string> ans;
        stack<string> st;
        st.push("JFK");
        while(!st.empty()){
            string curr = st.top();
            if(adj[curr].empty()){
                ans.push_back(curr);
                st.pop();
            }
            else{
                st.push(adj[curr].back());
                adj[curr].pop_back();            
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
