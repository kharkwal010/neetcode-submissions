class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        int count = 0;
        for(int i=0; i<apples.size(); i++){
            while(!minheap.empty() && minheap.top().first<i) minheap.pop();
            if(apples[i]!=0){
                minheap.push({i+days[i]-1, apples[i]});
            }
            if(minheap.empty()) continue;
            count++;
            pair<int, int> top = minheap.top();
            minheap.pop();
            if(top.second!=1) minheap.push({top.first, top.second-1});
        }
        int curr = days.size();
        while(!minheap.empty()){
            while(!minheap.empty() && minheap.top().first<curr){
                minheap.pop();
            }
            if(minheap.empty()) break;
            auto top = minheap.top();
            minheap.pop();
            int pick = min(top.first-curr+1, top.second);
            curr = curr+pick;
            count = count + pick;
        }
        return count;
    }
};