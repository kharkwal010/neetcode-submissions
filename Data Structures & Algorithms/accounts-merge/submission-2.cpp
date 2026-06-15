class DSU {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    DSU(int n){
        this->n = n;
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findpar(int n){
        if(parent[n] == n) return n;
        return parent[n] = findpar(parent[n]);
    }
    bool unionsets(int a, int b){
        int pa = findpar(a);
        int pb = findpar(b);
        if(pa==pb) return false;
        if(size[pa]>=size[pb]){
            parent[pb] = pa;
            size[pa] = size[pa] + size[pb];
        }
        else{
            parent[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> match;
        DSU uf(accounts.size());
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(match.count(accounts[i][j])){
                    uf.unionsets(i, match[accounts[i][j]]);
                }
                match[accounts[i][j]] = i;
            }
        }
        vector<vector<string>> ans;
        vector<vector<int>> par(accounts.size());
        for(int i=0; i<accounts.size(); i++){
            par[uf.findpar(i)].push_back(i);
        }
        unordered_set<string> visited;
        for(int i=0; i<accounts.size(); i++){
            if(par[i].empty()) continue;
            ans.push_back({});
            ans.back().push_back(accounts[par[i][0]][0]);
            for(int x: par[i]){
                for(int y=1; y<accounts[x].size(); y++){
                    if(visited.count(accounts[x][y])) continue;
                    ans.back().push_back(accounts[x][y]);
                    visited.insert(accounts[x][y]);
                }
            }
        }
        for(int i=0; i<ans.size(); i++){
            sort(ans[i].begin()+1, ans[i].end());
        }
        return ans;
    }
};