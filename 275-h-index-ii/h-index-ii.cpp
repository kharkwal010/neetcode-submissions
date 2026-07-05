class Solution {
public:
    int check(vector<int>& citations, int k){
        int n = citations.size();
        if(citations[0]>=k) return n;
        int l = 0;
        int r = n-1;
        while(l<=r){
            int m = l + (r - l) / 2;
            if(citations[m]>=k) r = m-1;
            else l = m+1;
        }
        return n - l;
    }

    int hIndex(vector<int>& citations) {
        // leftmost index of number greater than p, and find that max number;  --> n - i 
        int l = 0;
        int r = citations.size();
        while(l<=r){
            int m = l + (r-l) / 2;
            int num = check(citations, m);
            if(m>num) r = m - 1;
            else  l = m+1;
        }
        return l-1;
    }
};