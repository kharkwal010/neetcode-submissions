class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(string s: words) freq[s]++;
        priority_queue<pair<int, string>> maxheap;
        for(auto ele: freq){
            maxheap.push({500-ele.second, ele.first});
            if(maxheap.size()>k) maxheap.pop();
        }
        vector<string> ans;
        while(!maxheap.empty()){
            auto top = maxheap.top();
            maxheap.pop();
            ans.push_back(top.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};