class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       vector<int> ans(temperatures.size(),0);
       stack<pair<int, int>> stack;

       for(int i=0; i<temperatures.size()-1; i++){
        if(temperatures[i]<temperatures[i+1]){
            ans[i]=1;
            while(!(stack.empty())){
                auto temp = stack.top();
                if(temp.second< temperatures[i+1]){
                    ans[temp.first]= i+1-temp.first;
                    stack.pop();
                }
                else break;
            }
        }
        else stack.push({i, temperatures[i]});
       }
       return ans;
       
    }
};
