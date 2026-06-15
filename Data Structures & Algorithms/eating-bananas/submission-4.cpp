class Solution {
public:
    int check(vector<int>& piles, int rate){
        int sum= 0;
        for(int i=0; i<piles.size(); i++){
            sum = sum + ceil(double(piles[i])/rate);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int left = 1;
       int right = *max_element(piles.begin(), piles.end());
       int res = right;
        while(right>=left){
            int mid = (left + right)/2;
            if(check(piles, mid)<=h){
                res = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
           
        }
        return res;
    }
};
