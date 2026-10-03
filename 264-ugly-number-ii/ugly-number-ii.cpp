class Solution {
public:
    int nthUglyNumber(int n) {
       vector<int> terms = {2, 3, 5};
       priority_queue<int, vector<int>, greater<int>> minheap;
       for(int t: terms) minheap.push(t);
       if(n==1) return 1;
       n--;
       while(n>1){
            long long curr = minheap.top();
            minheap.pop();

            cout<<curr<<" ";
            if(curr%3!=0 && curr%5!=0){
                for(int t: terms){
                    if(curr*t>INT_MAX) break;
                    minheap.push(curr*t);
                }
            }
            else if(curr%5!=0){
                for(int i=1; i<terms.size(); i++){
                    if(curr*terms[i]>INT_MAX) break;
                    minheap.push(curr*terms[i]);
                }
            }
            else {
                if(curr*5<INT_MAX) minheap.push(curr*5);
            }
            n--;
       }
       cout<<minheap.top();
       return minheap.top();

    }
};