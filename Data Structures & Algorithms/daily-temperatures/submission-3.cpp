class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       stack<pair<int, int>> temp;
       vector<int> ans(temperatures.size(), 0);
       for(int i=0; i<temperatures.size(); i++){
        if(temp.empty() || temp.top().first > temperatures[i]){
            temp.push({temperatures[i], i});
        }
        else{
            while(!temp.empty() && temp.top().first < temperatures[i]){
                auto term = temp.top();
                temp.pop();
                ans[term.second] = i - term.second;
            }
            temp.push({temperatures[i],i});
        }
       }
       return ans;
    }
};
