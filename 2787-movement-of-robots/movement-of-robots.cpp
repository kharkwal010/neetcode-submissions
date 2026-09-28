class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long> terms;
        int mod = 1e9+7;
        for(int i=0; i<nums.size(); i++){
            if(s[i]=='R') terms.push_back((long long)nums[i] + d);
            else terms.push_back((long long)nums[i] - d);
        }
        sort(terms.begin(), terms.end());
        long long ans = 0;
        for(int i=0; i<terms.size()-1; i++){
            cout<<terms[i]<<" ";
            long long curr = (i+1)*terms[i+1] - terms[i];
            terms[i+1] = terms[i+1] + terms[i];
            ans = (ans + curr) % mod;
        } 
        return ans;   
        
    }
};