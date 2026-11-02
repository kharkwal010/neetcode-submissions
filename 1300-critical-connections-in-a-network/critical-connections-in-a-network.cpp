class Solution {
public:
    vector<int> time;
    vector<int> low;
    int t;
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& adj, int curr, int parent){
        time[curr] = t;
        low[curr] = t;
        t++;
        for(int nei: adj[curr]){
            if(nei==parent) continue;
            if(time[nei]==-1){
                dfs(adj, nei, curr);
                if(time[curr]<low[nei]){
                    ans.push_back({curr, nei});
                }
                else{
                    low[curr] = min(low[nei], low[curr]);
                }
            }
            else{
                low[curr] = min(low[nei], low[curr]);
            }
        }
        return;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        time.resize(n, -1);
        low.resize(n);
        t = 0;

        vector<vector<int>> adj(n);
        for(auto ed: connections){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        dfs(adj, 0, -1);
        return ans;



    }
};








/*
Tarzan's algo:
    here we cant use just one vector of time couse we cant use a return time,
    difficult to execute the required algo so instead we make a void function
    and use two vectors time (entry time) and low (lowest time that adjacent
     node can reach)--> this is low what we wanted to return so in total its 
    significance is just that it tells that node could have reached earlier
    ==> 
        if a node would have been part of the cycle its adj node (apart from 
        parent) will have low or equal value of low then the time of curr node.
*/