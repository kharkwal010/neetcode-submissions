class Solution {
public:   
    vector<int> cycle;
    int dfs(vector<vector<int>>& graph, int i){
        if(graph[i].empty()) return cycle[i] = 0;
        if(cycle[i]!=-1) return cycle[i];
        cycle[i] = INT_MAX;
        int ans = -1;
        for(int nei: graph[i]){
            ans = max(ans, dfs(graph, nei));
        }
        return cycle[i] = ans;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        cycle.resize(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            if(cycle[i]==-1) dfs(graph, i);
        }
        vector<int> ans;
        for(int i=0; i<cycle.size(); i++){
            if(cycle[i]==0) ans.push_back(i);
        }
        return ans;
    }
};