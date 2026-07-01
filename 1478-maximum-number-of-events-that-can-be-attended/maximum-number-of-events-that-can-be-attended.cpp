class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int time = 1;
        priority_queue<int, vector<int>, greater<int>> minheap;
        sort(events.begin(), events.end());
        int i = 0;
        int count = 0;
        while(i<events.size()){
            while(i<events.size() && time>=events[i][0]){
                minheap.push(events[i][1]);
                i++;
            }
            while(!minheap.empty() && time>minheap.top()) minheap.pop();
            if(!minheap.empty()){
                minheap.pop();
                count++;
            }
            time++;
        }
        while(!minheap.empty()){
            while(!minheap.empty() && time>minheap.top()) minheap.pop();
            if(!minheap.empty()){
                minheap.pop();
                count++;
            }
            time++;
        }
        return count;
    }
};