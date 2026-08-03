class Solution {
public:
    int dis(vector<int> p1, vector<int> p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int cost = 0;
        unordered_set<int> visited;          
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0, 0});
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            int c = top[0];
            int n = top[1];
            if(visited.count(n)) continue;
            visited.insert(n);
            cost += c;
            for(int i=0; i<points.size(); i++){
                if(visited.count(i)) continue;
                minheap.push({dis(points[n], points[i]), i});
            }
        }
        return cost;
        
    }
};
