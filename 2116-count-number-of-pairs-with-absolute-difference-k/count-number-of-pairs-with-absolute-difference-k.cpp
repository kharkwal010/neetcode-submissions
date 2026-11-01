class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int n: nums) freq[n]++;
        int ans = 0;
        for(auto& ele: freq){
            int t = ele.first;
            if(freq.count(t-k)){
                ans += freq[t] * freq[t-k];
            }
        }
        return ans;
    }
};