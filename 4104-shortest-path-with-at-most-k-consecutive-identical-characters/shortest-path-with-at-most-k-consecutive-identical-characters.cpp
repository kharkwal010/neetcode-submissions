class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto& ed: edges){
            adj[ed[0]].push_back({ed[2], ed[1]});
        }
        vector<vector<bool>> visited(n, vector<bool>(k + 1, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0, 1, 0});   // {weight, consi, node}
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            int nde = top[2];
            int freq = top[1];
            if(visited[nde][freq]) continue;
            visited[nde][freq] = true;
            int w = top[0];
            if(nde==n-1) return w;
            for(auto nei: adj[nde]){
                int nnode = nei[1];
                int time = nei[0];
                int nfreq = 1;
                if(labels[nde]==labels[nnode]){
                    if(freq==k) continue;
                    else nfreq = freq+1;
                }
                if(visited[nnode][nfreq]) continue;                
                minheap.push({w+time, nfreq, nnode});
            }
            
        }
        return -1;
    }
};