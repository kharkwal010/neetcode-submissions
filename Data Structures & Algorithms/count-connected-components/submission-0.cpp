class Solution {
public:
    void dfs(int i, set<int>& visited, vector<vector<int>> adj){
        if(visited.find(i)!=visited.end()){
            return;
        }
        else{
            visited.insert(i);
            for (int ad : adj[i]){
                dfs(ad, visited, adj);
            }
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        set<int> visited;
        vector<vector<int>> adj(n);
        int counter=0;
        for(auto element : edges){
            adj[element[0]].push_back(element[1]);
            adj[element[1]].push_back(element[0]);
        }
        for (int i =0; i<n; i++){
            if(visited.find(i)==visited.end()){
                dfs(i, visited, adj);
                counter++;
            }

        }
        return counter;
        
    }
};
