class Solution {
public:
    int nthUglyNumber(int n) {
       vector<int> terms = {2, 3, 5};
       priority_queue<long long, vector<long long>, greater<long long>> minheap;
       minheap.push(1);
       while(n>1){
            long long curr = minheap.top();
            minheap.pop();
            if(curr%5==0) minheap.push(curr*5);
            else if(curr%3==0){
                minheap.push(curr*3);
                minheap.push(curr*5);
            }
            else{
                for(int ele: terms) minheap.push(curr*ele);
            }
            n--;
       }
       return minheap.top();
    }
};