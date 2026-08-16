class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> rightmax(n+1, 0);
        for(int i=0; i<ranges.size(); i++){
            if(ranges[i]==0) continue;
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            rightmax[l] = max(rightmax[l], r);
        }
        int far = 0;
        int maxcurr = 0;
        int i = 0;
        int count = 0;
        while(i<n){
            while(i<=maxcurr){
                far = max(far, rightmax[i]);
                i++;
            }
            count++;
            if(far==n) return count;
            else if(far<=maxcurr) return -1;
            maxcurr = far;
        }
        return -1;

    }
};