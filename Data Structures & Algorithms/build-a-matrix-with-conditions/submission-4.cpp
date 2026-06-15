class Solution {
public:
    vector<int> order(int k, vector<int>& indegree, vector<vector<int>>& adj){
        vector<int> ans;
        queue<int> q;
        int count = 0;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0) q.push(i);
        } 
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            count++;
            for(int nei: adj[top]){
                indegree[nei]--;
                if(indegree[nei]==0){
                     q.push(nei);
                }
            }
        }
        if(count==k) return ans;
        return {};
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> radj(k);
        vector<vector<int>> cadj(k);
        vector<int> rindegree(k, 0);
        vector<int> cindegree(k, 0);
        for(auto r: rowConditions){
            radj[r[0]-1].push_back(r[1]-1);
            rindegree[r[1]-1]++;
        }
        for(auto c: colConditions){
            cadj[c[0]-1].push_back(c[1]-1);
            cindegree[c[1]-1]++;
        }
        vector<int> r = order(k, rindegree, radj);
        if(r.empty()) return {};
        vector<int> c = order(k, cindegree, cadj);
        if(c.empty()) return {};
        unordered_map<int, int> col;
        for(int i=0; i<c.size(); i++){
            col[c[i]+1] = i;
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i=0; i<k; i++){
            ans[i][col[r[i]+1]] = r[i]+1;
        }
        return ans;
    }
};