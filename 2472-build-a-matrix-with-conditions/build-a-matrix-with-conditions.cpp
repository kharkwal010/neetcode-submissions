class Solution {
public:
    vector<int> values(vector<vector<int>>& row, int k){
        vector<vector<int>> adj(k+1);
        vector<int> indegree(k+1, 0);
        for(auto e: row){
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        vector<int> ans;
        int count = 0;
        queue<int> q;
        for(int i=1; i<=k; i++){
            if(indegree[i]==0) q.push(i);            
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            ans.push_back(curr);
            for(int nei: adj[curr]){
                indegree[nei]--;
                if(indegree[nei]==0) q.push(nei);
            }
        }
        // cout<<count<<endl;
        // for(int ele: ans) cout<<ele<<" ";
        if(count==k) return ans;
        return {};
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> ver = values(rowConditions, k);
        if(ver.size()==0) return {};
        vector<int> hori = values(colConditions, k);
        if(hori.size()==0) return {};
        unordered_map<int, int> index;
        for(int i=0; i<k; i++){
            index[hori[i]] = i;
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i=0; i<k; i++){
            int curr = ver[i];
            ans[i][index[curr]] = curr;
        }
        return ans;        
    }
};