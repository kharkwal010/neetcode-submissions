class Solution {
public:
    set<int> visited;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int, int>>> adj(n);
       for(auto flight : flights){
        adj[flight[0]].push_back({flight[2], flight[1]});
       }
       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
       minheap.push({0,src,k+1});

       int node=src;
       int price = 0;
       while(!minheap.empty()){
        auto top= minheap.top();
        minheap.pop();
        price = top[0];
        node = top[1];
        int rem = top[2];
        visited.insert(node);
        if(node==dst){
            break;
        }
        
        if(rem==0 && node!=dst){
            continue;
        }
        
        for(auto nei: adj[node]){
            int neigh = nei.second;
            int cost = nei.first;
            if(visited.find(neigh)==visited.end()){
                minheap.push({price+cost,neigh, rem-1});
            }
        }
       }
       if(dst==node){
        return price;
       }
       else{
        return -1;
       }
       
    }
};
