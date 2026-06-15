class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][2], flights[i][1]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        unordered_set<int> visited;
        k=k+1;

        minheap.push({0, src, k});
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            if(top[2]<0){
                continue;
            }
            visited.insert(top[1]);
            for(auto nei: adj[top[1]]){
                int node = nei[1];
                int cost = nei[0];
                if(visited.find(node)==visited.end()){
                    minheap.push({top[0]+cost, node, top[2]-1});
                }
            }
            if(top[1]==dst){
                return top[0];
            }

        }
        return -1;

    }
};
