class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int time = 1;
        priority_queue<int, vector<int>, greater<int>> minheap;
        sort(events.begin(), events.end());
        int i = 0;
        int count = 0;
        while(i<events.size() || !minheap.empty()){
            if(minheap.empty()) time = events[i][0];
            while(i<events.size() && time>=events[i][0]){
                minheap.push(events[i][1]);
                i++;
            }
            while(!minheap.empty() && minheap.top()<time) minheap.pop();
            if(!minheap.empty()){
                minheap.pop();
                time++;
                count++;
            }
        }
        return count;           
    }
};