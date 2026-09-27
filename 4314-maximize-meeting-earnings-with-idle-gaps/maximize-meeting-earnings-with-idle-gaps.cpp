class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
       sort(meetings.begin(), meetings.end());
       long long ans = 0;
       pair<int, long long> p_best = {INT_MAX, 0};
       priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> minheap;
        for(auto& m: meetings){
            while(!minheap.empty() && minheap.top().first<=m[0]){
                auto top = minheap.top();
                minheap.pop();
                long long score = m[0] - top.first + top.second;
                long long p_score = m[0] - p_best.first + p_best.second;
                if(p_score<score){
                    p_best = top;
                }
            }
            long long curr = p_best.second;
            if(p_best.first!=INT_MAX) curr += m[0] - p_best.first;
            ans = max(ans, curr + m[2]);
            minheap.push({m[1], curr+m[2]});
        }
        return ans;

    }
};