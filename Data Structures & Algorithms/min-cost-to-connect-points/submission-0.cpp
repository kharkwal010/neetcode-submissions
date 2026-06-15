class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> queue;
        unordered_set<int> visited;
        int cost = 0;
        queue.push({0,0});
        while(!(queue.empty())){
            vector<int> top = queue.top();
            queue.pop();
            if (visited.find(top[1])!=visited.end()){
                continue;
            }
            visited.insert(top[1]);
            cost = cost + top[0];
            
            for(int j=0; j<points.size(); j++){
                if(visited.find(j)==visited.end()){
                int distance= abs(points[top[1]][0]-points[j][0])+abs(points[top[1]][1]-points[j][1]);
                queue.push({distance, j});
                }
            }

            if(visited.size()==points.size()){
                break;
            }
        }
        return cost;
    }
};
