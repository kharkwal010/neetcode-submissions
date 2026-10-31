class Solution {
public:
    int bfs(vector<vector<int>>& adj, int& last, int curr){
        int count = 0;
        queue<pair<int, int>> q;
        q.push({curr, -1});
        while(!q.empty()){
            int sz = q.size();
            last = q.front().first;
            for(int i=0; i<sz; i++){
                auto[nde, par] = q.front();
                q.pop();
                for(int nei: adj[nde]){
                    if(nei==par) continue;
                    q.push({nei, nde});
                }
            }
            count++;
        }
        return count;
    }
    int finddia(vector<vector<int>>& edges){
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(auto ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        int last = 0;
        bfs(adj, last, 0);
        int d1 = bfs(adj, last, last);
        return d1-1;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = finddia(edges1);
        int d2 = finddia(edges2);
        return max({d1, d2, (d1+1)/2 + (d2+1)/2 + 1});
        
    }
};