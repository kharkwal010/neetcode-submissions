class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       priority_queue<int> exist;
       priority_queue<int> popping;
       for(int i=0; i<k; i++){
        exist.push(nums[i]);
       }
       vector<int> result;
       result.push_back(exist.top());
       for(int i=0; i+k<nums.size(); i++){
        if(nums[i]==exist.top()){
            exist.pop();
            while(!(popping.empty()) && !(exist.empty()) && popping.top()==exist.top()){
                popping.pop();
                exist.pop();
            }
        }
        else{
            popping.push(nums[i]);
        }
        exist.push(nums[i+k]);
        result.push_back(exist.top());
       }
       return result;
    }
};
