class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<double, string>>> adj;
        for(int i=0; i<values.size(); i++){
            adj[equations[i][0]].push_back({values[i], equations[i][1]});
            adj[equations[i][1]].push_back({1/values[i], equations[i][0]});
        }
        vector<double> ans;
        for(auto ele: queries){
            string src = ele[0];
            string dst = ele[1];
            if(!adj.count(src) || !adj.count(dst)){
                 ans.push_back(-1);
                 continue;
            }
            if(src==dst){
                ans.push_back(1);
                continue;
            }
            queue<pair<double, string>> q;
            unordered_set<string> visited;
            bool finish = false;
            q.push({1, src});
            while(!q.empty()){
                double val = q.front().first;
                string node = q.front().second;
                q.pop();
                if(visited.count(node)) continue;                
                visited.insert(node);
                if(node==dst){
                    ans.push_back(val);
                    finish = true;
                    break;
                }
                for(auto nei: adj[node]){
                    if(visited.count(nei.second)) continue;
                    q.push({val*nei.first, nei.second});
                }
            }
            if(!finish) ans.push_back(-1);
            
        }
        return ans;
    }
};