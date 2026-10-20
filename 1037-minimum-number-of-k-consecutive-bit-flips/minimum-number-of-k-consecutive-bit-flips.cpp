class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int count= 0;
        int n = nums.size(); 
        vector<int> prefix(n+1, 0);
        for(int i=0; i<nums.size(); i++){
            if(i>0) prefix[i] += prefix[i-1];
            if((nums[i]+prefix[i])%2==0){
                if(i+k>=prefix.size()) return -1;
                count++;
                prefix[i] += 1;
                prefix[i+k] -= 1;
            }
        }
        return count;
    }
};