class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n);
        if(target==1){
            if(edges.size()==0) return 1;
            return 0;
        }
        for(auto ed: edges){
            adj[ed[0]-1].push_back(ed[1]-1);
            adj[ed[1]-1].push_back(ed[0]-1);
        }
        queue<pair<int, int>> q;
        for(int nei: adj[0]){
            q.push({nei, 0});
        }
        adj[0].push_back(-1);
        t--;

        vector<double> prob(n, 0);
        prob[0] = 1;
        while(!q.empty() && t>=0){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto curr = q.front();
                q.pop();
                int par = curr.second;
                int nde = curr.first;
                int num = adj[par].size()-1;
                if(num>0) prob[nde] = 1.0/num * prob[par];
                if(nde==target-1){
                    if(t>0){
                        if(adj[nde].size()>1) return 0;
                        else return prob[nde];
                    }
                    return prob[nde];
                }
                for(int nei: adj[nde]){
                    if(nei==curr.second) continue;
                    q.push({nei, nde});
                }
            }
            t--;
        }
        return 0;

        
    }
};