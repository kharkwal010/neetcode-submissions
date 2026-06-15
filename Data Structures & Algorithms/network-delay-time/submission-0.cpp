class Solution {
public:
    set<int> visited;
   
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int time = 0;
        vector<vector<pair<int, int>>> adj(n);
        for(auto& elements : times){
            adj[elements[0]-1].push_back({elements[2], elements[1]-1});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0,k-1});
       
        while (!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            if (visited.find(top[1])!=visited.end()){
                continue;
            }
            visited.insert(top[1]);
            time = max(time,top[0]);
            for (auto& nei : adj[top[1]]){
                int one = nei.first + top[0];
                int two = nei.second;
                minheap.push({one, two});
            }

        }
        if (visited.size()==n){
            return time;
        }
        return -1;


    }
};
