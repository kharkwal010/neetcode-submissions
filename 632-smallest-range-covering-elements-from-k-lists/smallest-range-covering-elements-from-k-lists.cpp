class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> mindel;
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            minheap.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        }
        int interval = maxi - minheap.top()[0];
        vector<int> ans = {minheap.top()[0], maxi};
        while(true){
            auto top = minheap.top();
            minheap.pop();
            int r = top[1];
            int c = top[2];
            if(c==nums[r].size()-1) break;
            minheap.push({nums[r][c+1], r, c+1});
            maxi = max(maxi, nums[r][c+1]);
            if(maxi-minheap.top()[0]<interval){
                interval = maxi - minheap.top()[0];
                ans = {minheap.top()[0], maxi};
                if(interval==0) break;
            }            
        }
        return ans;
    }
};