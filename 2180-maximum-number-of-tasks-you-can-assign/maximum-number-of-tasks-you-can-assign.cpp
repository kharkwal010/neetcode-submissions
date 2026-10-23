class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k){
        deque<int> dq;
        int j = 0;
        for(int i=k-1; i>=0; i--){
            while(j<k && workers[j] + strength >= tasks[i]){
                dq.push_back(workers[j]);
                j++;
            }
            if(dq.empty()) return false;
            if(dq.front()>=tasks[i]) dq.pop_front();
            else{
                if(pills==0) return false;
                pills--;
                dq.pop_back();
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int l = 0;
        int r = min(tasks.size(), workers.size());
        sort(tasks.begin(), tasks.end());
        sort(workers.rbegin(), workers.rend());

        int ans = 0;
        while(l<=r){
            int m = (l+r)/2;
            if(check(tasks, workers, pills, strength, m)){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};