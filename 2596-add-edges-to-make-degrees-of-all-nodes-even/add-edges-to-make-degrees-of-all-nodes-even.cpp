class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto ed: edges){
            adj[ed[0]-1].insert(ed[1]-1);
            adj[ed[1]-1].insert(ed[0]-1);
            indegree[ed[0]-1]++;
            indegree[ed[1]-1]++;
        }
        vector<int> ankit;
        for(int i=0; i<n; i++){
            if(indegree[i]%2==1) ankit.push_back(i);
        }
        if(ankit.size()>4) return false;
        if(ankit.size()==2){
            int a = ankit[0];
            int b = ankit[1];
            for(int i=0; i<n; i++){
                if(!adj[a].count(i) && !adj[b].count(i)) return true;
            }
            return false;
        }
        if(ankit.size()==4){
            for(int i=1; i<4; i++){
                if(!adj[ankit[0]].count(ankit[i])){
                    int a = -1;
                    int b = -1;
                    for(int j=1; j<4; j++){
                        if(j==i) continue;
                        if(a!=-1) b = ankit[j];
                        else a = ankit[j];
                    }
                    if(!adj[a].count(b)) return true;
                }
            }
            return false;
        }

        return true;
        
    }
};