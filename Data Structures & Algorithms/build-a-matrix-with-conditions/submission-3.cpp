class Solution {
public:
    vector<int> bfs(int k, vector<vector<int>>& rowConditions){  
        vector<int> col;      
        vector<vector<int>> adj(k);
        vector<int> indegree(k, 0);
        for(auto ele: rowConditions){
            adj[ele[0]-1].push_back(ele[1]-1);
            indegree[ele[1]-1]++;
        }
        queue<int> q;
        for(int i=0; i<k; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            col.push_back(top+1);
            for(int ele: adj[top]){
                indegree[ele]--;
                if(indegree[ele]==0){
                    q.push(ele);
                }
            }
        }
        if(col.size()==k) return col;
        return {}; 
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {        
        vector<int> col = bfs(k, rowConditions);
        if(col.size()==0) return {};
        vector<int> row = bfs(k, colConditions);
        if(row.size()==0) return {};
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