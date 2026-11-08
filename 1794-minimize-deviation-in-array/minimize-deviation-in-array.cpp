class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        int maxi = 0;
      for(int n: nums){
        int temp = n;
        if(n%2==1){
            minheap.push({n, 2*n});
        }
        else{
            while(n%2==0) n = n/2;
            minheap.push({n, temp});
        }
        maxi = max(maxi, n);
      }
      int ans = INT_MAX;
        while(true){
            auto curr = minheap.top();
            minheap.pop();
            int a = curr.first;
            int maxa = curr.second;
            ans = min(ans, maxi - a);
            if(a==maxa) break;
            maxi = max(maxi, 2*a);
            minheap.push({2*a, maxa});
        }
        return ans;


    }
};