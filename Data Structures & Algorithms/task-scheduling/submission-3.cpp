class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> count(26,0);
       for(char task: tasks){
            count[task-'A']++;
       }
       priority_queue<int> maxheap;
       for(int i: count){
            if(i>0){
                maxheap.push(i);
            }
       }
       queue<pair<int, int>> queue;
       int time = 0;
       while(!maxheap.empty() || !queue.empty()){
            if(!maxheap.empty()){
                int top = maxheap.top();
                maxheap.pop();
                if(top>1){
                    queue.push({top-1, time + n});
                }
            }
            if(!queue.empty() && queue.front().second==time){
                int front = queue.front().first;
                maxheap.push(front);
                queue.pop();
            }
            
            time++;
            
            
       }
       return time;
    }
};
