class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        unordered_map<int, unordered_map<int, int>> freq;
        int ans = 0;
        int equal = 0;
        for(int i=0; i<nums.size()-1; i++){
            int a = min(nums[i], nums[i+1]);
            int b = max(nums[i], nums[i+1]);
            if(a==b) equal++;
            freq[a][b]++;
        }
        ans = equal;
        for(auto& e: freq){
            int a = e.first;
            for(auto& t: e.second){
                int b = t.first;
                if(a==b) continue;
                else ans = max(ans, freq[a][b] + equal);
            } 
        }
        return ans;
    }
};