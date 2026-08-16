class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l = 0;
        while(l<arr.size()-1){
           if(arr[l]<=arr[l+1]) l++;
           else break;
        }
        if(l==arr.size()-1) return 0;
        int r = arr.size()-1;
        while(r>0){
            if(arr[r]>=arr[r-1]) r--;
            else break;
        }
        int n = arr.size();
        int ans = max(l+1, n-r);
        int i=0;
        int j=r;
        while(i<=l && j<n){
            if(arr[i]<=arr[j]){
                ans = max(ans, i+1 + n-j);
                i++;
            }
            else{
                j++;
            }
        }
        return n - ans;
        

        
    }
};