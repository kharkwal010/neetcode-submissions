class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1<<n)-1;
        vector<vector<bool>> visited(n, vector<bool>(1<<n, false));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            int mask = 1<<i;
            q.push({i, mask});
            visited[i][mask] = true;
        }
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int k=0; k<sz; k++){
                auto[nde, mask] = q.front();
                q.pop();
                if(mask==target) return step;
                for(int nei: graph[nde]){
                    int newmask = mask | 1<<nei;
                    if(visited[nei][newmask]) continue;
                    visited[nei][newmask] = true;
                    q.push({nei, newmask});
                }
            }
            step++;
        }
        return -1;

    }
};


/*
here the bitmask and node will tell that i am at this node 
and i have visited all these node till now..., so if at a step 
i reach to a node with same node already visited, might be by diffrent
path so will stop that path and continue from other only

here the bitmask is the ith position 1 indicating that node is visited
*/