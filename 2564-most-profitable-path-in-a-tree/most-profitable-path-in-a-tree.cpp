class Solution {
public:
    vector<bool> path;
    bool dfs(vector<vector<int>>& adj, int bob, int parent){
        if(bob==0) return path[bob] = true;
        bool ans = false;
        for(int nei: adj[bob]){
            if (nei==parent) continue;
            ans = ans || dfs(adj, nei, bob);
        }
        return path[bob] = ans;
    }
    vector<int> btime;
    void pathbob(vector<vector<int>>& adj, int bob){
        queue<int> q;
        int time = 0;
        q.push(bob);
        while(!q.empty()){
            bob = q.front();
            q.pop();
            btime[bob] = time;
            path[bob] = false;
            for(int nei: adj[bob]){
                if(path[nei]) q.push(nei);
            }
            time++;
        }
        return;
    }

    int val(vector<vector<int>>& adj, int alice, int aparent, vector<int>& amount, int time){
        long long curr = 0;
        if(time==btime[alice]) curr = amount[alice]/2;
        else if(time<btime[alice]) curr = amount[alice];
        int sum = curr;
        int nxt = INT_MIN;
        if (adj[alice].size() == 1 && alice != 0) return curr;
        for(int nei: adj[alice]){
            if(nei==aparent) continue;            
            nxt = max(nxt, val(adj, nei, alice, amount, time+1));
        }
        return sum + nxt;
    }

    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        path.assign(n, 0);
        vector<vector<int>> adj(n);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(adj, bob, -1);
        btime.assign(n, INT_MAX);
        pathbob(adj, bob);
        return val(adj, 0, -1, amount, 0);
        
    }
};