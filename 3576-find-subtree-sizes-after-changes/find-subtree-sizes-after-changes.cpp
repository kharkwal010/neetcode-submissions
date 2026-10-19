class Solution {
public:
    void shift(vector<vector<int>>& adj, vector<int>& parent, vector<int> values, int curr, string& s){
        if(values[s[curr]-'a']!=-1) parent[curr] = values[s[curr]-'a'];
        values[s[curr]-'a'] = curr;
        for(int nei: adj[curr]){
            shift(adj, parent, values, nei, s);
        }
        values[s[curr]-'a'] = -1;
    }

    vector<int> size;
    int dfs(vector<vector<int>>& adj, int curr){
        int sz = 1;
        for(int nei: adj[curr]){
            sz += dfs(adj, nei);
        }
        return size[curr] = sz;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i=1; i<parent.size(); i++){
            adj[parent[i]].push_back(i);
        }
        vector<int> values(26, -1);
        shift(adj, parent, values, 0, s);
        vector<vector<int>> nadj(n);
        for(int i=1; i<parent.size(); i++){
            nadj[parent[i]].push_back(i);
        }
        // for(int p: parent) cout<<p<<" ";
        size.resize(n, 0);
        dfs(nadj, 0);
        return size;
    }
};