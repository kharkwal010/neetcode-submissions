class Solution {
public:
    void bfs(vector<int>& col, int k, bool& valid, vector<vector<int>>& rowConditions){
        vector<bool> present(k, 0);
        vector<vector<int>> adj(k);
        vector<int> indegree(k, 0);
        int c = 0;
        for(auto ele: rowConditions){
            present[ele[0]-1] = true;
            present[ele[1]-1] = true;
            adj[ele[0]-1].push_back(ele[1]-1);
            indegree[ele[1]-1]++;
        }

        int pre = 0;
        for(int i=0; i<k; i++){
            pre += present[i];
        }
        queue<int> q;
        for(int i=0; i<k; i++){
            if(indegree[i]==0 && present[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            col[c] = top+1;
            c++;
            for(int ele: adj[top]){
                indegree[ele]--;
                if(indegree[ele]==0){
                    q.push(ele);
                }
            }
        }
        if(pre!=c) valid = false;
        else{
            for(int i=0; i<k; i++){
                if(!present[i]){
                    col[c] = i+1;
                    c++;
                }
            }
        }
        return;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {        
        vector<int> col(k,-1);
        bool valid = true;
        bfs(col, k, valid, rowConditions);
        if(!valid) return {};
        vector<int> row(k,-1);
        valid = true;
        bfs(row, k, valid, colConditions);
        if(!valid) return {};
        unordered_map<int, int> pos;
        int i=0;
        for(int ele: row){
            pos[ele] = i;
            i++;
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        i=0;
        for(auto& ele: col){
            ans[i][pos[ele]] = ele;
            i++;
        }
        return ans;    
        

    }
};