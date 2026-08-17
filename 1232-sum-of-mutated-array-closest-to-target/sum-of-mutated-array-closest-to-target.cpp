class Solution {
public:
    int sumdiff(vector<int>& arr, int& target, int m){
        int sum = 0;
        for(int ele: arr){
            sum += min(m, ele);
        }
        return abs(target - sum);
    }

    int findBestValue(vector<int>& arr, int target) {
        int r = *max_element(arr.begin(), arr.end());
        int l = 0;
        while(l<=r){
            int m = (l+r)/2;            
            int one = sumdiff(arr, target, m);
            int next = sumdiff(arr, target, m+1);
            if(one<=next){
                r = m-1;
            }
            else l = m+1;            
        }
        return l;

    }
};