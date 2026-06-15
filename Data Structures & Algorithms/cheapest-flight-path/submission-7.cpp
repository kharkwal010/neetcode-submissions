class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k = k+1;
        vector<vector<pair<int, int>>> adj(n);
        for(auto fl: flights){
            adj[fl[0]].push_back({fl[2], fl[1]});
        }
        unordered_set<int> visited;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0, src, k});

        int curr;
        int price;
        int pos;
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            curr = top[1];
            visited.insert(curr);
            price = top[0];
            if(curr==dst){
                return price;
            }
            pos = top[2];
            for(auto nei: adj[curr]){
                if(pos>0 && visited.find(nei.second)==visited.end()){
                    minheap.push({price + nei.first, nei.second, pos-1});
                }
            }
        }
        return -1;
       
    }
};
