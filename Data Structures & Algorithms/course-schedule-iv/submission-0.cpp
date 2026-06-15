class Solution {
public:
    unordered_map<int, unordered_set<int>> pres;
    unordered_set<int> visited;
    void dfs(vector<vector<int>>& adj, int curr){
        if(visited.count(curr)) return;
        visited.insert(curr);
        for(auto& nei: adj[curr]){
            if(!visited.count(nei)) dfs(adj,nei);
        }
        return;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(auto& items: prerequisites){
            adj[items[0]].push_back(items[1]);
        }
        vector<bool> ans(queries.size(), false);
        for(int i=0; i<queries.size(); i++){
            if(!pres[queries[i][0]].count(-1)){
                dfs(adj, queries[i][0]);
                pres[queries[i][0]] = visited;
                pres[queries[i][0]].insert(-1);
                visited.clear();
            }
            if(pres[queries[i][0]].count(queries[i][1])) ans[i] = true;
        }
        return ans;

    }
};