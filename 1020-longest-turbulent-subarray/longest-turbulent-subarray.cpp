class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int r = 1;
        int l = 0;
        int ans = 1;
        bool asc = true;
        while(r<arr.size()){
            if(arr[r-1]==arr[r]){
                r++;
                l = r-1;
            }
            else{
                if(arr[r-1]<arr[r]) asc = true;
                else asc = false;
                while(r<arr.size()){
                    if(asc && arr[r]<=arr[r-1]) break;
                    if(!asc && arr[r]>=arr[r-1]) break;
                    asc = !asc;
                    r++;
                }
                ans = max(ans, r-l);
                l=r-1;
            }
        }
        return ans;
    }
};