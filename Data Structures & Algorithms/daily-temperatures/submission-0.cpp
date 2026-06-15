class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> counter(temperatures.size(),0);
        stack <pair<int, int>> temp;
        for (int i=0; i<temperatures.size(); i++){
            int t = temperatures[i];
            while (!temp.empty() && temp.top().first < t){
                int rank = temp.top().second;
                temp.pop();
                counter[rank] = i-rank;

            }
            temp.push({t,i});
        }
        return counter;
       
    }
};
