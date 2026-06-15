class Solution {
public:
    int distance(vector<int> points){
        return points[0]*points[0]+ points[1]*points[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        for(vector<int> point: points){
            minheap.push({distance(point),  point[0], point[1]});
        }
        vector<vector<int>> ans;
        for(int i=0; i<k; i++){
            vector<int> one = minheap.top();
            minheap.pop();
            ans.push_back({one[1], one[2]});
        }
        return ans;
    }
};
