class Solution {
public:
    vector<int> size;
    vector<vector<int>> adj;
    int dfs(vector<int>& parent, int node){
        int sz = 1;
        for(int nei: adj[node]){
            if(nei==parent[node]) continue;
            sz += dfs(parent, nei);
        }
        return size[node] = sz;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        adj.resize(n);
        for(int i=1; i<parents.size(); i++){
            int p = parents[i];
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
        size.resize(n);
        dfs(parents, 0);
        // for(int s: size) cout<<s<<" ";
        // cout<<endl;
        vector<long long> score(n, 0);
        for(int i=0; i<n; i++){
            long long sc = 1;
            int par = n-1;
            for(int nei: adj[i]){
                if(nei==parents[i]) continue;
                sc *= size[nei];
                par -= size[nei];
            }
            // cout<<sc<<endl;
            if(par>0) sc*=par;
            score[i] = sc;
        }
        long long maxi = *max_element(score.begin(), score.end());
        int count = 0;
        for(long long e:  score){
            // cout<<e<<" ";
            if(e==maxi) count++;
        }
        return count;
    }
};