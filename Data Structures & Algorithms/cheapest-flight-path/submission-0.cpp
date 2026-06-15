class Solution {
public:
    set<int> visited;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& elem: flights){
            adj[elem[0]].push_back({elem[2], elem[1]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0,src,k});
        int cost = -1;
        
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            if (top[2]<-1){
                continue;
            }
            if (top[1]==dst){
                cost = top[0];
                break;
            }
            visited.insert(top[1]);
            for (auto& nei : adj[top[1]]){
                if(visited.find(nei.second)==visited.end()){
                    minheap.push({nei.first+top[0], nei.second, top[2]-1});
                }
            }

        }
        return cost;
    }
};
