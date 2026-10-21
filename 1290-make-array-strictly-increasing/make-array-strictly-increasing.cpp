class Solution {
public:
    int inf = 1e5;
    map<pair<int,int>, int> memo;
    int solve(vector<int>& arr1, vector<int>& arr2, int i, int prev){
        if(i==arr1.size()) return 0;
        if(memo.count({i, prev})) return memo[{i, prev}];
        int ans = inf;
        if(arr1[i]>prev) ans = min(ans, solve(arr1, arr2, i+1, arr1[i]));
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if(it!=arr2.end()) {
            int j = it - arr2.begin();
            ans = min(ans, 1 + solve(arr1, arr2, i+1, arr2[j]));
        }
        
        return memo[{i, prev}] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int m = arr1.size();
        int n = arr2.size();
        int ans = solve(arr1, arr2, 0, INT_MIN);
        if(ans==inf) return -1;
        return ans;
        
    }
};