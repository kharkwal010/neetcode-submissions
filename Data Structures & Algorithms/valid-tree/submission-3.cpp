class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adj(n);
       unordered_set<int> visited;
       for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
       }
       queue<pair<int, int>> queue; 
       int nodes = 0;      
        queue.push({-1, 0});          // -1 is the prev node to save us from loop;
       
       while(!(queue.empty())){
        auto curr = queue.front();
        queue.pop();
        nodes++;
        if(visited.find(curr.second)!=visited.end()){
            return false;
        }
        visited.insert(curr.second);
        for(int nei: adj[curr.second]){
            if(nei!=curr.first){
                queue.push({curr.second, nei});
            }
        }
       }
       if(nodes==n){
        return true;
       }
       return false;

    }
};
