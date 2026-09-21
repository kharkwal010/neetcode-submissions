class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major;
        int freq = 0;
        for(int n: nums){
            if(freq==0){
                major = n;
                freq = 1;
            }
            else{
                if(n==major) freq++;
                else freq--;
            }
        }
        return major;
    }
};