class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      priority_queue<int> maxheap;
      unordered_map<int, int> count;
      int i=0;
      for(int num: nums){
        if(i==k) break;
        maxheap.push(num);
        count[num]++;
        i++;
      }
      vector<int> ans;
      int start=0;
      ans.push_back(maxheap.top());
      while(i<nums.size()){
        maxheap.push(nums[i]);
        count[nums[i]]++;
        count[nums[start]]--;
        while(count[maxheap.top()]==0){
            maxheap.pop();
        }
        ans.push_back(maxheap.top());
        start++;
        i++;
      }
      return ans;
    }
};
