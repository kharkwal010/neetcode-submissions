class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<pair<long long, int>> terms;
        long long sum = 0;
        terms.push_back({0, -1});
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int tar = sum - k;
            if(terms[0].first<=tar){
                int l = 0;
                int r = terms.size()-1;
                int curr = l;
                while(l<=r){
                    int m = (l+r)/2;
                    if(terms[m].first<=tar){
                        curr = m;
                        l = m+1;
                    }
                    else r = m-1;
                }
                ans = min(ans, i-terms[curr].second);            
            }
            while(terms.size()>0 && terms.back().first>=sum){
                terms.pop_back();
            }
            terms.push_back({sum, i});

        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};