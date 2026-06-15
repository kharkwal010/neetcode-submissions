class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> count(26,0);
       for (int i=0; i<tasks.size(); i++){
        count[tasks[i]-'A']++;
       }
       priority_queue<int> maxheap;
       for(int i=0; i<26; i++){
        if(count[i]>0){
        maxheap.push(count[i]);
        }
       }
       queue<pair<int,int>> queue;
       int time=0;
       while(maxheap.size()>0 || queue.size()>0){
       int one=0;
        if (maxheap.size()>0){
        one = maxheap.top();
        maxheap.pop();
        }
        time++;
        if(queue.size()>0){
            auto second = queue.front();
            int sec = second.second;
            if(sec == time){
                maxheap.push(second.first);
                queue.pop();
            }
            
        }
        if (one>1){
            queue.push({one-1,time+n});
        }
       }
       return time;
    }
};
