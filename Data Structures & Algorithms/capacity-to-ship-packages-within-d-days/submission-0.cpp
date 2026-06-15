class Solution {
public:
    bool check(vector<int>& weights, int days, int cap){
        int sum = 0;
        int count = 0;
        for(int i=0; i<weights.size(); i++){
            sum = sum + weights[i];
            if(sum>cap){
                sum = weights[i];
                count++;
            }
        }
        if(count<days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = INT_MIN;
        int r = 0;
        for(int w: weights){
            l = max(l, w);
            r += w;
        }
        while(l<r){
            int m = (l+r) / 2;
            if(check(weights, days, m)) r = m;
            else l = m+1;
        }
        return l;
    }
};