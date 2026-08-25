class Solution {
public:
    priority_queue<pair<int, int>> minheap;
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        sort(buildings.begin(), buildings.end());
        vector<vector<int>> ans;
        int i = 0;
        while(i<buildings.size()){
            int st = buildings[i][0];
            int end = buildings[i][1];
            int height = buildings[i][2];
            if(minheap.empty()){
                ans.push_back({st, height});
                minheap.push({height, end});
                i++;
                continue;
            }
            int prev = minheap.top().second;
            int ph = minheap.top().first;
            if(prev>=st){
                // cout<<ph<<" "<<height<<endl;
                if(ph<height){
                    if(ans.back()[0]==st){
                        height = max(height, ans.back()[1]);
                        ans.pop_back();                        
                    }
                    ans.push_back({st,height});
                }
                minheap.push({height, end});
                i++;
            }
            else{
                minheap.pop();
                while(!minheap.empty() && minheap.top().second<=prev) minheap.pop();
                int h = (minheap.empty()) ? 0: minheap.top().first;
                ans.push_back({prev, h});
            }
        }
        while(!minheap.empty()){
            int prev = minheap.top().second;
            minheap.pop();
            while(!minheap.empty() && minheap.top().second<=prev) minheap.pop();
            int h = (minheap.empty()) ? 0: minheap.top().first;
            ans.push_back({prev, h});
        }
        return ans;
    }
};