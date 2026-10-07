class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> changes(n+1, 0);
        int flips = 0;
        for(int i=0; i<n; i++){
            if(i>0) changes[i] += changes[i-1];
            int curr = (changes[i] + nums[i])%2;
            if(curr==0){
                if(i+k>n) return -1;
                flips++;
                changes[i+k]-=1;
                changes[i]+=1;
            }
        }
        return flips;
    }
};