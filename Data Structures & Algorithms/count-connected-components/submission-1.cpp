class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, unordered_set<int>& visited){
        if(visited.find(i)!=visited.end()){
            return;
        }
        visited.insert(i);
        for(int nei: adj[i]){
            dfs(nei, adj, visited);
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        int counter=0;
        unordered_set<int> visited;
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0; i<n; i++){
           if(visited.find(i)==visited.end()){
                counter++;
                dfs(i, adj, visited);
           } 
        }
        return counter;
        
    }
};
