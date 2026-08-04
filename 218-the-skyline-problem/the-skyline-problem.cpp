class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
       priority_queue<pair<int, int>> maxheap;
       vector<vector<int>> ans;
       int i = 0;
       while(i<buildings.size() || !maxheap.empty()){
            int x;
            if(maxheap.empty() || (i<buildings.size() && maxheap.top().second>=buildings[i][0])){
                x = buildings[i][0];
            }
            else{
                x = maxheap.top().second;
                maxheap.pop();
            }
            while(i<buildings.size() && buildings[i][0]<=x){
                maxheap.push({buildings[i][2], buildings[i][1]});
                i++;
            }
            while(!maxheap.empty() && maxheap.top().second<=x){
                maxheap.pop();
            }
            int h = (maxheap.empty()) ? 0 : maxheap.top().first;
            if(ans.size()==0 || ans.back()[1]!=h){
                ans.push_back({x, h});
            }
            
       }
       return ans;
    }
};