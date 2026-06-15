class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        priority_queue<int> maxheap;
        for(int i=0; i<capital.size(); i++){
            minheap.push({capital[i], profits[i]});
        }
        for(int i=0; i<k; i++){
            while(!minheap.empty() && minheap.top()[0]<=w){
                int ele = minheap.top()[1];
                minheap.pop();
                maxheap.push(ele);
            }
            if(maxheap.empty()) return w;
            w = w + maxheap.top();
            maxheap.pop();
        }
        return w;
    }
};