class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> freq;
        for(int b: barcodes) freq[b]++;
        priority_queue<pair<int, int>> maxheap;
        for(auto ele: freq){
            maxheap.push({ele.second, ele.first});
        }
        vector<int> ans;
        auto top = maxheap.top();
        maxheap.pop();
        ans.push_back(top.second);
        pair<int, int> prev = {top.first-1, top.second};

        while(!maxheap.empty()){
            top = maxheap.top();
            maxheap.pop();
            ans.push_back(top.second);
            if(prev.first!=0) maxheap.push(prev);
            prev = {top.first-1, top.second};
        }
        return ans;
    }
};