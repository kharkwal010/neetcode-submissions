class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxheap;
        queue<pair<int, int>> cage;
        vector<int> count(26,0);
        for(char task: tasks){
            count[task-'A']++;
        }
        for(int i=0; i<26; i++){
            if (count[i]>0){
                maxheap.push(count[i]);
            }
        }
        int time=0;
        while(!maxheap.empty() || !cage.empty()){
            if(!maxheap.empty()){
                int top = maxheap.top();
                maxheap.pop();
                if(top>1){
                    cage.push({time+n, top-1});
                }
            }
            if(!cage.empty() && time==cage.front().first){
                maxheap.push(cage.front().second);
                cage.pop();
            }
            time++;
        }
        return time;
    }
};
