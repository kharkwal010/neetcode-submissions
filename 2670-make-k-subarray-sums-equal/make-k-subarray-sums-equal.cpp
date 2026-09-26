class Solution {
public:
    long long match(vector<int>& terms){
        int n = terms.size();
        sort(terms.begin(), terms.end());
        int m = terms[(n-1)/2];
        long long c = 0;
        for(int e: terms) c+=abs(e-m);
        return c;
    }
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        int g = gcd(n, k);
        if(g==n) return 0;
        vector<vector<int>> terms(g);
        for(int i=0; i<arr.size(); i++){
            int j = i%g;
            terms[j].push_back(arr[i]);
        }
        // cout<<g<<endl;
        long long count = 0;
        for(auto& t: terms){
            count += match(t);
        }
        return count;
        

    }
};