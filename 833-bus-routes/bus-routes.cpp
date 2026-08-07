class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
       unordered_map<int, vector<int>> bus;
       for(int i=0; i<routes.size(); i++){
            for(int r: routes[i]){
                bus[r].push_back(i);
            }
       }
       unordered_set<int> tar;
       for(int b: bus[target]){
        tar.insert(b);
       }
       queue<int> q;
       int n = routes.size();
       vector<bool> visited(n, false);
       for(int b: bus[source]){
            if(tar.count(b)) return 1;
            visited[b] = true;
            q.push(b);
       }
       vector<unordered_set<int>> adj(routes.size());
       for(auto ele: bus){
        if(ele.second.size()<2) continue;
        vector<int> terms = ele.second;
        for(int i=0; i<terms.size(); i++){
            for(int j=i+1; j<terms.size(); j++){
                adj[terms[i]].insert(terms[j]);
                adj[terms[j]].insert(terms[i]);
            }
        }
       }
       int count = 1;
       
       while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int curr = q.front();
                q.pop();
                if(tar.count(curr)) return count;
                for(int nei: adj[curr]){
                    if(visited[nei]) continue;
                    visited[nei] = true;
                    q.push(nei);
                }
            }
            count++;
       }
       return -1;

    }
};  
