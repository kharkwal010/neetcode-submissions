class Solution {
public:
    vector<int> terms(string& s){
        stringstream ss(s);
        vector<int> values;
        string curr;
        while(getline(ss, curr, ':')){
            int val = 0;
            if(curr=="start" || curr=="end"){
                if(curr=="end") val = 1;
            }
            else val = stoi(curr);
            values.push_back(val);
        }
        return values;
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
      vector<int> ans(n, 0);
      stack<pair<int, int>> st;
      for(int i=0; i<logs.size(); i++){
            vector<int> val = terms(logs[i]);
            if(val[1]==0){
                if(!st.empty()){
                    auto prev = st.top();
                    // cout<<prev.first<<" "<<prev.second<<endl;
                    ans[prev.first] += val[2] - prev.second;

                }
                // cout<<val[0]<<" "<<val[2]<<endl;
                st.push({val[0], val[2]});
            }
            else{
                auto prev = st.top();
                st.pop();
                ans[prev.first] += val[2] - prev.second + 1;
                if(!st.empty()){
                    int pnode = st.top().first;
                    st.pop();
                    st.push({pnode, val[2]+1});
                    
                }
            }
      }
      return ans;
    }
};