class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int mod = 1e9 + 7;
        long long sum = 0;
        for(int a: arr) sum += a;
        long long left = 0;
        long long right = 0;
        long long curr = 0;
        for(int a: arr){
            curr += a;
            left = min(left, curr);
        }
        curr = 0;
        for(int i=arr.size()-1; i>=0; i--){
            curr += arr[i];
            right = min(right, curr);
        }
        long long complete = k*sum;
        if(sum>0) complete -=  (left + right);
        vector<int> temp = arr;
        if(k>1) for(int a: arr) temp.push_back(a);
        long long sub = 0;
        curr = 0;
        for(int& a: temp){
            curr += a;
            sub = max(sub, curr);
            if(curr<0) curr = 0;
        }
        long long ans = max(complete, sub);
        return ans%mod;
        
    }
};