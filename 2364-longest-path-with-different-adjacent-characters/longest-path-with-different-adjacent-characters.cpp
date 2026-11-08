class Solution {
public:
    int ans = 0;
    int path(vector<vector<int>>& adj, string& s, int curr, int parent){
        int first = 0;
        int second = 0;
        for(int nei: adj[curr]){
            int ns = path(adj, s, nei, curr);
            if(s[curr]!=s[nei]){
                if(ns>=first){
                    second = first;
                    first = ns;
                }
                else if(ns>second) second = ns;
            }
        }
        ans = max(ans, first + second + 1);
        return 1 + first;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> adj(n);
        for(int i=1; i<n; i++){
            adj[parent[i]].push_back(i);
        }
        path(adj, s, 0, -1);
        return ans;

    }
};