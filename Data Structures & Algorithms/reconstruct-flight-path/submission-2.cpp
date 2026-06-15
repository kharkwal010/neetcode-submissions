class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> nei;
        for(auto& t: tickets){
            nei[t[0]].push_back(t[1]);
        }
        for(auto& n: nei){
            sort(n.second.rbegin(), n.second.rend());
        }
        stack<string> s;
        vector<string> ans;
        s.push("JFK");
        while(!s.empty()){
            string top = s.top();
            if(nei[top].size()==0){
                ans.push_back(top);
                s.pop();
            }
            else{
                s.push(nei[top].back());
                nei[top].pop_back();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
