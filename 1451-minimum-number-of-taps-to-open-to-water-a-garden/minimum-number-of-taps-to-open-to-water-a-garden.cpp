class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
       vector<int> jumps(n+1, 0);
       for(int i=0; i<ranges.size(); i++){
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            jumps[left] = max(jumps[left], right); 
       }
       int count = 0;
       int prev_far = 0;
       int i = 0;
       while(i<n){
            int far = prev_far;
            for(int j=i; j<=prev_far; j++){
                far = max(far, jumps[j]);
            }
            if(prev_far==far) return -1;
            count++;
            i = prev_far+1;
            prev_far = far;
            if(far==n) return count;

       }
       return count;
              
    }
};