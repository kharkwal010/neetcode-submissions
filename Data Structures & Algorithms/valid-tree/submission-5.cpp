class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> visited;
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<pair<int, int>> nodes;
        nodes.push({0,-1});
        int finish=0;
        while(!nodes.empty()){
            auto top = nodes.front();
            nodes.pop();
            visited.insert(top.first);
            finish++;
            for(int nei: adj[top.first]){
                if(nei!=top.second){
                    if(visited.find(nei)!=visited.end()){
                        return false;
                    }
                    nodes.push({nei, top.first});
                }
            }
        }
        if(finish==n){
            return true;
        }
        return false;



    }
};
