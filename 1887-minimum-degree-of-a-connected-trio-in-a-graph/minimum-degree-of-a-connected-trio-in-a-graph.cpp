class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int mdegree = INT_MAX;
        vector<unordered_set<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto e: edges){
            adj[e[0]-1].insert(e[1]-1);
            adj[e[1]-1].insert(e[0]-1);
            indegree[e[0]-1]++;
            indegree[e[1]-1]++;
        }

        for(int i=0; i<n; i++){
            int curr = i;
            vector<int> neigh;
            for(int nei: adj[curr]){
                if(nei>curr) neigh.push_back(nei);
            }
            for(int j=0; j<neigh.size(); j++){
                for(int k=j+1; k<neigh.size(); k++){
                    if(adj[neigh[j]].count(neigh[k])){
                        mdegree = min(mdegree, indegree[curr] + indegree[neigh[j]] + indegree[neigh[k]] - 6);
                    }
                }
            }
        }
        return (mdegree==INT_MAX) ? -1 : mdegree;
    }
};