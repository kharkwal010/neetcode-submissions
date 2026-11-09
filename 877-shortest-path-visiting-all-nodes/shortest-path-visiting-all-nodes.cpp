class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
       int n = graph.size();
       vector<vector<bool>> vis(n, vector<bool>((1<<n)+1, false));
       queue<pair<int, int>> q;
       for(int i=0; i<n; i++){
            q.push({i, 1<<i});
            vis[i][1<<i] = true;
       }
       int cnt = 0;
    //    cout<<(1<<n)-1<<endl;
       while(!q.empty()){
            int sz = q.size();
            for(int k = 0; k<sz; k++){
                auto[curr, mask] = q.front();
                q.pop();
                // cout<<curr<<" "<<mask<<endl;
                if(mask==((1<<n)-1)) return cnt;
                for(int nei: graph[curr]){
                    int nmask = mask | (1<<nei);
                    if(vis[nei][nmask]) continue;
                    vis[nei][nmask] = true;
                    q.push({nei, nmask});
                }
            }
            cnt++;
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