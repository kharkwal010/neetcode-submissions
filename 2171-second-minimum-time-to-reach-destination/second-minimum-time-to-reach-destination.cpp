class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n);
        for(auto ed: edges){
            adj[ed[0]-1].push_back(ed[1]-1);
            adj[ed[1]-1].push_back(ed[0]-1);
        }

        vector<vector<int>> visited(n, vector<int>(2, -1));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0, 0});

        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            int node = top[1];
            int cost = top[0];
            if(visited[node][1]!=-1) continue;
            if(visited[node][0]==-1) visited[node][0] = cost;
            else if(visited[node][0]==cost) continue;
            else visited[node][1] = cost;
            // cout<<node<<" "<<cost<<endl;
            if(node==n-1 && visited[node][1]!=-1) return cost;

            for(int nei: adj[node]){
                if(visited[nei][1]!=-1) continue;
                if((cost/change)%2==1) cost += change - cost%change;
                minheap.push({cost+time, nei});
            }
        }
        return -1;
    }
};