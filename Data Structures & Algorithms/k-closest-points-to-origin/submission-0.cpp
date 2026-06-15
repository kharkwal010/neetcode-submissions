class Solution {
public:
    int distance(vector<int> points) {
        int dis = (points[0] * points[0] + points[1] * points[1]);
        return dis;
}
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int, pair<int, int>>> maxheap;
       int count=0;
       for(int i=0; i<points.size(); i++){
        maxheap.push({distance(points[i]), {points[i][0], points[i][1]}});
        count++;
        if (count>k){
            maxheap.pop();
        }
       }
        vector<vector<int>> result;
        int i=0;
       while(maxheap.size()!=0){
            auto top = maxheap.top();
            int one = top.second.first;
            int two = top.second.second;
            result.push_back({one, two});
            maxheap.pop();
            i++;
       }
       return result;
       
    }
};
