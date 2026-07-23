class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
       unordered_map<int, unordered_map<long long, int>> prev;
       long long prefix = 0;
       long long ans = 0;
       for(int i=0; i<capacity.size(); i++){
            long long comp = prefix - 2*capacity[i];
            ans += prev[capacity[i]][comp];
            prev[capacity[i]][prefix]++;
            if(i>0 && capacity[i]==0 && capacity[i-1]==0) ans--;
            prefix += capacity[i];
       }
       return ans;
    }
};