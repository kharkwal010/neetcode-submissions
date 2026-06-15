class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> count;
      count[0] = 1;
      int presum = 0;
      int ans=0;
      for(int num: nums){
        presum = num + presum;
        if(count.find(presum-k)!=count.end()){
            ans = ans + count[presum-k];
        }
        count[presum]++;
      }
      return ans;
    }
};