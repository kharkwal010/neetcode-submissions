class Solution {
public:
    vector<int> btime;
    bool traverse(vector<vector<int>>& adj, int bob, int parent, int time){
        if(bob==0){
            btime[bob] = time;
            return true;
        }
        bool status = false;
        for(int nei: adj[bob]){
            if(nei==parent) continue;
            status = status || traverse(adj, nei, bob, time+1);
        }
        if(status){
            btime[bob] = time;
            return true;
        }
        return false;
    }

    void profit(vector<vector<int>>& adj, int nde, int& ans, int curr, int parent, int time, vector<int>& amount){
        int contri = amount[nde];
        if(time>btime[nde]) contri = 0;
        else if(time==btime[nde]) contri = contri / 2;
        
        if(adj[nde].size()==1 && parent!=-1){
            // cout<<curr<<endl;
            ans = max(ans, curr + contri);
            return;
        }

        for(int nei: adj[nde]){
            if(nei==parent) continue;            
            profit(adj, nei, ans, curr + contri, nde, time+1, amount);
            // cout<<nei<<" "<<curr + contri<<endl;
        }
        return;

    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size()+1;
        btime.resize(n, INT_MAX);
        vector<vector<int>> adj(n);
        for(auto& ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        traverse(adj, bob, -1, 0);

        int ans = INT_MIN;
        profit(adj, 0, ans, 0, -1, 0, amount);
        return ans;


        
    }
};