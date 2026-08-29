class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int ans = INT_MAX;
        while(i<arr.size()-1){
            if(arr[i]<=arr[i+1]) i++;
            else break;
        }
        if(i==arr.size()-1) return 0;
        ans = min(ans, n-i-1);
        int j = arr.size()-1;
        while(arr[j]>=arr[j-1]) j--;
        ans = min(ans, j);
        int r = arr.size()-1;
        while(i>=0 and r>=j){
            while(i>=0 && arr[i]>arr[r]) i--;
            ans = min(ans, r-i-1);
            r--;
        }
        return ans;

    }
};