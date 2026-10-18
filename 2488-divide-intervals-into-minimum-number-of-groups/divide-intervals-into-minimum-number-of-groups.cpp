class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for(auto e: intervals){
            starts.push_back(e[0]);
            ends.push_back(e[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int s = 0;
        int e = 0;
        int group = 0;
        int ans = 0;
        while(s<starts.size()){
            if(starts[s]<=ends[e]){
                group++;
                ans = max(group, ans);
                s++;
            }
            else{
                group--;
                e++;
            }
        }
        return ans;
    }
};