class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> one;
        unordered_map<int, int> two;

        unordered_set<int> terms;
        for(int n: nums1){
            one[n]++;
            terms.insert(n);
        }
        for(int n: nums2){
            terms.insert(n);
            two[n]++;
        }
        long long ans = 0;
        for(int t: terms){
            int first = one[t];
            int second = two[t];
            if((first+second)%2==1) return -1;
            ans += abs(first-second);
        }
        return ans/4;
        
    }
};