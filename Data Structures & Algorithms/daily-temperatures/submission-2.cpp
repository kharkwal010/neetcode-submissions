class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       vector<int> ans(temperatures.size(),0);
       stack<pair<int, int>> stack;
       stack.push({temperatures[0],0});
        for(int i=1; i<temperatures.size(); i++){
            while(!stack.empty() && stack.top().first<temperatures[i]){
                auto top = stack.top();
                stack.pop();
                ans[top.second]=i-top.second;
            }
            stack.push({temperatures[i],i});
        } 
        return ans; 
       
    }
};
