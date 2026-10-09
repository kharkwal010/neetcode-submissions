class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        // first check;
        unordered_map<int, int> one;
        unordered_map<int, int> second;
        for(int i=0; i<nums.size(); i++){
            one[nums[i]]++;
            second[forbidden[i]]++;
        }
        int n = nums.size();
        for(auto& ele: one){
            int node = ele.first;
            int freq = ele.second;
            if(second[node]>n-freq) return -1;
        }

        unordered_map<int, int> mismatch;
        for(int i = 0; i<n; i++){
            if(nums[i]==forbidden[i]) mismatch[nums[i]]++;
        }
        priority_queue<int> pq;
        for(auto& ele: mismatch) pq.push(ele.second);
        int swap = 0;
        while(pq.size()>1){
            int top = pq.top();
            pq.pop();
            int sec = pq.top();
            pq.pop();
            if(top>1) pq.push(top-1);
            if(sec>1) pq.push(sec-1);
            swap++;
        }
        if(pq.empty()) return swap;
        int top = pq.top();
        return swap + top;
    }
};