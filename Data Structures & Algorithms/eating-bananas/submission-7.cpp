class Solution {
public:
    int check(vector<int> piles, int rate){
        int sum = 0;
        for(int ele: piles){
            sum = sum + ceil((double)ele/rate);
        }
        return sum;        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int start = 1;
      int res = start;
      int end = *max_element(piles.begin(), piles.end());
      while(start<=end){
        int mid = (start + end)/2;
        if(check(piles, mid)<=h){
            res = mid;
            end = mid-1;
        }
        else {
            start = mid+1;
        }
      }
      return res;
    }
};
