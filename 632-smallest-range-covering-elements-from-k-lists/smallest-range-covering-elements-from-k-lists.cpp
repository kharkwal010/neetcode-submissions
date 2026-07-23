class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
       vector<int> index(nums.size(), 0);
       int curr = INT_MAX;
       vector<int> ans;
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
       int maxi = INT_MIN;
       for(int i=0; i<nums.size(); i++){
        minheap.push({nums[i][0], i});
        maxi = max(maxi, nums[i][0]);
       }
       while(true){
        auto top = minheap.top();
        minheap.pop();
        int mini = top.first;
        int imin = top.second;        
        // cout<<maxi<<" "<<mini<<endl;
        if(curr>maxi-mini){
            curr = maxi - mini;
            ans = {mini, maxi};
        }
        index[imin]++;
        int j = index[imin];
        if(j==nums[imin].size()) break;      
        maxi = max(maxi, nums[imin][j]);
        minheap.push({nums[imin][j], imin});        
       }
       return ans;
    }
};