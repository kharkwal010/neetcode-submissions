class Solution {
public:
    vector<int> time;
    vector<int> low;
    vector<bool> visited;
    vector<vector<int>> adj;
    int timer;
    vector<vector<int>> ans;
    void dfs(int parent, int node){
        if(visited[node]) return;
        visited[node]= true;
        low[node] = time[node] = timer;
        timer++;
        for(int nei: adj[node]){
            if(nei==parent) continue;
            dfs(node, nei);
            low[node] = min(low[node], low[nei]);
        }
        if(time[parent]<low[node]) ans.push_back({node, parent});
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       timer = 0;
       time.resize(n, INT_MAX);
       low.resize(n, INT_MAX);
       visited.resize(n, false);
       adj.resize(n);
       for(auto& edges: connections){
            adj[edges[0]].push_back((edges[1]));
            adj[edges[1]].push_back(edges[0]);
       }
       dfs(0, 0);
       return ans;
    }
};