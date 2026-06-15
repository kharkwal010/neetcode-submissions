class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int , int> number;
        for (int num : nums){
            number[num]++;
        }
        priority_queue<vector<int>> maxheap;
        for (auto& p: number){
            maxheap.push({p.second, p.first});
        }
            
        vector<int> a;
        for (int i=0; i<k; i++){
            auto top = maxheap.top();
            maxheap.pop();
            a.push_back(top[1]);            
        }
        return a;
    }
};
