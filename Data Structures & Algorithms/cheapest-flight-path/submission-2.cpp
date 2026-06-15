class Solution {
public:
    set<int> visited;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight: flights){
            adj[flight[0]].push_back({flight[2],flight[1]});  //{cost, nei};
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0,src,k+1});  // +1 for source and destination --->used in neighbour allocation
        int cost ;
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();

                    int curr_loc = top[1];
                    int steps = top[2];            
                    cost = top[0];
            
            if(curr_loc==dst){
                return cost;
            }
            visited.insert(curr_loc);

            for(auto nei: adj[curr_loc]){
                int price = nei.first+cost;
                int des = nei.second;
                if(visited.find(des)==visited.end()){   
                    if(steps>0){             
                    minheap.push({price, des, steps-1});
                    }
                 }
            }
        }
        return -1;
    }
};
