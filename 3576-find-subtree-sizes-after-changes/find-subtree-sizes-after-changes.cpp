class Solution {
public:
    vector<int> anscestors;
    vector<vector<int>> alist(vector<int>& parent){
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i=1; i<parent.size(); i++){
            adj[parent[i]].push_back(i);
        }
        return adj;
    }

    void dfs(vector<vector<int>>& adj, int curr, string& s, vector<int>& values){
        if(values[s[curr]-'a']!=-1){
            anscestors[curr] = values[s[curr]-'a'];
        }
        int old = values[s[curr]-'a'];
        values[s[curr]-'a'] = curr;
        for(int nei: adj[curr]){
            dfs(adj, nei, s, values);
        }
        values[s[curr]-'a'] = old;
        return;
    }
    vector<int> result;
    int size(vector<vector<int>>& adj, int node){
        int ans = 1;
        for(int nei: adj[node]){
            ans += size(adj, nei);
        }
        return result[node] = ans;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        anscestors.resize(n, -1);
        vector<int> values(26,-1);
        vector<vector<int>> adj = alist(parent);
        dfs(adj, 0, s, values);
        for(int i=0; i<n; i++){
            if(anscestors[i]!=-1) parent[i] = anscestors[i];
        }
        // for(int p: parent) cout<<p<<" ";
        adj = alist(parent);
        result.resize(n, 0);
        size(adj, 0);
        return result;
    }
};