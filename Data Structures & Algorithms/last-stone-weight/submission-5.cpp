class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(int i=0; i<stones.size(); i++){
            maxheap.push(stones[i]);
        }
        while (true){
            if (maxheap.size()==0){
                return 0;
            }
            if(maxheap.size()==1){  
                return maxheap.top();
            }
            int one = maxheap.top();
            maxheap.pop();
            int two = maxheap.top();
            maxheap.pop();
            int stone = (one-two);
            if (stone!=0){
                maxheap.push(stone);
            }
        }
    }
};
