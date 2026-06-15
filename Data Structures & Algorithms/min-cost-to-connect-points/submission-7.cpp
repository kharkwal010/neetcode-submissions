class Solution {
public:
    int dis(vector<int> p1, vector<int> p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0,0});
        unordered_set<int> visited;
        int ans = 0;
        int j=0;
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            int node = top[1];
            int dist = top[0];
            if(visited.count(node)) continue;
            ans = ans + dist;
            visited.insert(node);
            for(int i=1; i<points.size(); i++){
                if(i==node || visited.count(i)) continue;
                minheap.push({dis(points[node], points[i]), i});
            }
           
        }
        return ans;
    }
};
