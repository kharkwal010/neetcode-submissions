class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxheap;
        vector<int> count(26,0);
        for(char ele: tasks){
            count[ele-'A']++;
        }
        for(int ele: count){
            if(ele>0){
                maxheap.push(ele);
            }
        }
        queue<pair<int, int>> q;
        int time=0;
        while(!(maxheap.empty() && q.empty())){

            if(!maxheap.empty()){
                int topp = maxheap.top();
                maxheap.pop();
                if(topp>1){
                    q.push({topp-1, time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                auto top2 = q.front();
                q.pop();
                maxheap.push(top2.first);
            }
            time++;
        }
        return time;
    }
};
