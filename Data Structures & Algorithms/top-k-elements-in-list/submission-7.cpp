class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxheap;
        unordered_map<int, int> count;
        for(int num: nums){
            count[num]++;
        }
        for(auto num: count){
            maxheap.push({num.second, num.first});
        }
        vector<int> ans;
        for(int i=0; i<k; i++){
            int top = maxheap.top().second;
            ans.push_back(top);
            maxheap.pop();
        }
        return ans;
    }
};
