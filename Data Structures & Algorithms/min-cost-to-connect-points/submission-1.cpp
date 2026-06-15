class Solution {
public:
    int dis(vector<int> p1, vector<int> p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0,0});
        unordered_set<int> visited;
        int dist = 0;
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            int node = top[1];
            if(visited.find(node)!=visited.end()) continue;
            dist += top[0];
            visited.insert(node);
            if(visited.size()==points.size()) return dist;
            for(int i=0; i<points.size(); i++){
                if(visited.find(i)==visited.end()){
                    int d = dis(points[node], points[i]);
                    minheap.push({d,i});
                }
            }
        }
        return dist;
    }
};
