class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> ins;
        priority_queue<int> del;
        vector<int> ans;
        for(int i=0; i<k; i++){
            ins.push(nums[i]);
        }
        ans.push_back(ins.top());
        for(int i=k; i<nums.size(); i++){
            del.push(nums[i-k]);
            ins.push(nums[i]);
            while(!del.empty() && ins.top()==del.top()){
                ins.pop();
                del.pop();
            }
            ans.push_back(ins.top());
        }
        return ans;
    }
};
