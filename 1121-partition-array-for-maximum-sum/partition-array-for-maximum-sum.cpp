class Solution {
public:
    vector<int> memo;
    int sum(vector<int>& arr, int& k, int i){
        if(i==arr.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        int ans = 0;
        int maxi = 0;
        int end = min(i+k, (int)arr.size());
        for(int j=i; j<end; j++){
            maxi = max(maxi, arr[j]);
            ans = max(ans, maxi*(j-i+1) + sum(arr, k, j+1));
        }
        return memo[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int n = arr.size();
      memo.resize(n, -1);
      return sum(arr, k, 0);
    }
};