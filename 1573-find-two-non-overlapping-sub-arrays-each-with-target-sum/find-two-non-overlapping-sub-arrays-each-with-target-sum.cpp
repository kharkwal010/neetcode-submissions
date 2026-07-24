class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sum = 0;
        int n = arr.size();
        unordered_map<int, int> index;
        index[0] = -1;
        vector<int> left(arr.size(), INT_MAX);
        vector<int> right(arr.size(), INT_MAX);
        int curr = INT_MAX;
        for(int i=0; i<arr.size(); i++){
            left[i] = curr;
            sum += arr[i];
            if(index.count(sum-target)) curr = min(curr, i - index[sum-target]);
            index[sum] = i;
        }
        curr = INT_MAX;
        sum = 0;
        index.clear();
        index[0] = n;
        for(int i=n-1; i>=0; i--){
            sum += arr[i];
            if(index.count(sum-target)) curr = min(curr, index[sum-target] - i);
            right[i]= curr;
            index[sum] = i;
        }
        long long ans = INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, (long long)left[i] + right[i]);
        }
        return (ans==INT_MAX) ? -1 : ans;

    }
};