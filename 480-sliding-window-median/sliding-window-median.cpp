class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> low;
        priority_queue<int, vector<int>, greater<int>> high;

        for(int i=0; i<k; i++){
            low.push(nums[i]);
        }

        for(int i=0; i<k/2; i++){
            high.push(low.top());
            low.pop();
        }

        vector<double> ans;
        double curr = (k%2!=0) ? low.top() : ((double)low.top() + (double)high.top())/2;
        ans.push_back(curr);
        int next = 0;

        unordered_map<int, int> remove;
        for(int i=k; i<nums.size(); i++){
            remove[nums[i-k]]++;
            bool left = 0;            

            if(low.top()>=nums[i-k]){
                left = true;
            }

            if(left) low.push(nums[i]);
            else high.push(nums[i]);

            if(!high.empty() && low.top()>high.top()){
                int a = low.top();
                int b = high.top();
                low.pop();
                high.pop();
                low.push(b);
                high.push(a);
            }

            while(remove[low.top()]>0){
                remove[low.top()]--;
                low.pop();
            }

            while(!high.empty() && remove[high.top()]>0){
                remove[high.top()]--;
                high.pop();
            }

            curr = (k%2!=0) ? low.top() : ((double)low.top() + (double)high.top())/2;
            ans.push_back(curr);            
        }

        return ans;

    }
};