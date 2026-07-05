class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int> prefix(arr.size(), INT_MAX);
        vector<int> suffix(arr.size(), INT_MAX);
        unordered_map<int, int> index;
        index[0] = -1;
        int mini = INT_MAX;
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            if(index.count(sum - target)){
                mini = min(mini, i - index[sum - target]);
            }
            prefix[i] = mini;
            index[sum] = i;
        }
        index.clear();
        index[0] = arr.size();
        sum = 0;
        mini = INT_MAX;
        for(int i=arr.size()-1; i>=0; i--){
            sum+=arr[i];
            if(index.count(sum - target)){
                mini = min(mini, index[sum - target] - i);
            }
            suffix[i] = mini;
            index[sum] = i;
        }
        long long ans = INT_MAX;
        for(int i=0; i<arr.size(); i++){
            long long prev = (i>0) ? prefix[i-1] : INT_MAX;
            ans = min(ans, prev + suffix[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};