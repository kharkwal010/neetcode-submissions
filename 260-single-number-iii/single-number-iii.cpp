class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int ele: nums){
            ans = ans ^ ele;
        }
        int i = 0;
        while(true){
            int curr = (ans>>i) & 1;
            if(curr==1) break;
            i++;
        }
        int one = 0;
        int two = 0;
        for(int ele: nums){
            if((ele>>i & 1)==0) {
                one = one ^ ele;
            }
            else{
                two = two ^ ele;
            }
        }
        return {one, two};
    }
};