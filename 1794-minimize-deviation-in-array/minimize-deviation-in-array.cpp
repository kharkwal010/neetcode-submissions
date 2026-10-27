class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        int maxi = 0;
        for(int n: nums){
            int temp = n;
            while(n%2==0){
                n = n/ 2;
            }
            int upper = max(temp, 2*n);
            minheap.push({n, upper});
            maxi = max(maxi, n);
        }
        int n =  nums.size();
        int ans = INT_MAX;
        while(minheap.size()==n){
            auto[curr, currmax] = minheap.top();
            minheap.pop();
            ans = min(ans, maxi - curr);
            if(curr<currmax){
                minheap.push({curr*2, currmax});
                maxi = max(maxi, curr*2);
            }

        }
        return ans;
        
        

    }
};