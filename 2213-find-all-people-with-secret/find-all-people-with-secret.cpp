class Solution {
public: 
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<vector<int>>> adj(n);
        for(auto e: meetings){
            adj[e[0]].push_back({e[2], e[1]});
            adj[e[1]].push_back({e[2], e[0]});
        } 
        vector<int> knows(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0,0});
        q.push({0,firstPerson});
        while(!q.empty()){
            auto curr = q.top();
            q.pop();
            int t = curr.first;
            int nde = curr.second;
            if(knows[nde]) continue;
            knows[nde] = true;
            for(auto nei: adj[nde]){
                if(nei[0]<t || knows[nei[1]]) continue;
                q.push({nei[0], nei[1]});

            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++) if(knows[i]) ans.push_back(i);
        return ans;


    }
};