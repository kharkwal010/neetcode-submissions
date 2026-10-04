class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
       map<int, long long> terms;
       for(auto s: segments){
            int st = s[0];
            int end = s[1];
            int color = s[2];
            terms[st]+=color;
            terms[end]-=color;
       }
        int prev = -1;
        long long prevcol = 0;
        vector<vector<long long>> ans;
        for(auto& [curr, color]: terms){
            if(prev!=-1 && prevcol != 0){
                ans.push_back({prev, curr, prevcol});
            }
            prevcol = color + prevcol;
            prev = curr;
        }
        return ans;
       

    }
};

