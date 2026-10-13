class Solution {
public:   
    long long val(vector<int>& terms){
        sort(terms.begin(), terms.end());
        int n = terms.size()/2;
        int m = terms[n];
        long long ans = 0;
        for(int t: terms){
            ans += abs(t - m);
        }
        return ans;
    }
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        int div = gcd(n, k);
        vector<vector<int>> terms(div);
        for(int i=0; i<arr.size(); i++){
            terms[i%div].push_back(arr[i]);
        }
        long long ans = 0;
        for(vector<int> sub: terms){
            // for(int e: sub) cout<<e<<" ";
            // cout<<endl;
            ans += val(sub);
        }
        return ans;       

    }
};