class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        // mod bhi lagana h...
        int mod = 1e9+7;
        vector<int> terms;
        int t = 1;
        for(int i=0; i<21; i++){
            terms.push_back(t);
            t = t*2;
        }
        sort(deliciousness.begin(), deliciousness.end());
        unordered_map<int, int> count;
        long long ans = 0;
        int i = 0;
        for(int del: deliciousness){
            while(del>terms[i]){
                i++;
            }
            if(del==terms[i]) ans = (ans + count[del] + count[0])%mod;
            else ans = (ans + count[terms[i]-del])%mod;
            count[del]++;

        }
        return ans;

    }
};