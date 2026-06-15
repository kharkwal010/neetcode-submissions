class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char, int> count;
       for(char ele: tasks){
        count[ele]++;
       }
       priority_queue<int> maxheap;
       for(auto element: count){
        maxheap.push(element.second);
       }
       queue<pair<int,int>> queue;
       int time = 0;
        while(!(queue.empty() && maxheap.empty())){
            if(!maxheap.empty()){
                auto top = maxheap.top();
                maxheap.pop();
                if(top>1){
                    queue.push({top-1, time+n});
                }
            }
            if(!queue.empty() && queue.front().second==time){
                auto front = queue.front();
                queue.pop();
                maxheap.push(front.first);
            }
            time++;
        }
        return time;
    }
};
