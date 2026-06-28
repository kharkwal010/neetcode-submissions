class Solution {
public:    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(), stations.end());
        priority_queue<int> maxheap;
        int curr = startFuel;
        int count = 0;
        int i=0;
        while(curr<target){
            while(i<stations.size() && stations[i][0]<=curr){
                maxheap.push(stations[i][1]);
                i++;
            }
            if(maxheap.empty()) return -1;
            curr += maxheap.top();
            count++;
            maxheap.pop();
        }
        return count;
        
    }
};