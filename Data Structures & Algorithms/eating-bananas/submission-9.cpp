class Solution {
public:
    long check(vector<int> piles, int rate){
        long sum = 0;
        for(int ele: piles){
            sum = sum + ceil((double)ele/rate);
        }
        return sum;        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int start = 1;
      int end = *max_element(piles.begin(), piles.end());
      while(start<end){
        int mid = (start+end)/2;
        if(check(piles, mid)<=h) end = mid;
        else start = mid+1;        
      }  
      return start;    
    }
};
