class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day = 1;
        queue<pair<long long, int>> q;
        unordered_set<int> caged;
        for(int i=0; i<tasks.size(); i++){            
            while(caged.count(tasks[i])){
                auto curr = q.front();
                q.pop();
                day = max(day, curr.first);
                caged.erase(curr.second);
            }
            caged.insert(tasks[i]);
            q.push({day+space+1, tasks[i]});
            // cout<<day<<" "<<tasks[i]<<endl;
            day++;
        }
        return day-1;

    }
};