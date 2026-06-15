class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> occupied;
        priority_queue<int, vector<int>, greater<int>> free;
        vector<int> times(n,0);
        for(int i=0; i<n; i++){
            free.push(i);
        }
        int i = 0;
        sort(meetings.begin(), meetings.end());
        int time = 0;
        while(i<meetings.size()){
            if(free.size()==0){
                auto top = occupied.top();
                occupied.pop();
                time = top[0];
                free.push(top[1]);
            }
            if(time<meetings[i][0]) time = meetings[i][0];
            while(!occupied.empty() && occupied.top()[0]<=time){
                    free.push(occupied.top()[1]);
                    occupied.pop();
                }
            int curr = free.top();
            free.pop();
            occupied.push({time+meetings[i][1]-meetings[i][0], curr});
            times[curr] += 1;
            i++;
        }


        int ans = -1;
        int res = -1;
        for(int i=0; i<times.size(); i++){
            if(times[i]>ans){
                ans = times[i];
                res = i;
            }
        }
        return res;


    }
};