class Solution {
public:
    unordered_map<int, bool> memo;
    bool dfs(vector<vector<int>>& graph, int i){
        if(graph[i].size()==0){
            return memo[i] = true;
        }
        if(memo.count(i)) return memo[i];
        memo[i] = false;        // wapis aaye to false krde
        bool ans = true;
        for(int nei: graph[i]) ans = ans && dfs(graph, nei);
        return memo[i] = ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i=0; i<n; i++){
            if(!memo.count(i)) dfs(graph, i);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(memo[i]) ans.push_back(i);
        }
        return ans;
    }
};