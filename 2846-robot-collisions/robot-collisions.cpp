class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> terms;
        unordered_map<int, int> pos;
        for(int i=0; i<positions.size(); i++){
            int dir = (directions[i]=='L') ? 0 : 1;
            terms.push_back({positions[i], healths[i], dir});
            pos[positions[i]] = i;
        }
        sort(terms.begin(), terms.end());
        stack<vector<int>> st;
        for(int i=0; i<positions.size(); i++){
            if(st.empty() || st.top()[2]==0 || terms[i][2]==1){
                st.push(terms[i]);
                continue;
            }
            int heal = terms[i][1];
            bool insert = true;
            while(!st.empty() && st.top()[2]!=0){
                if(st.top()[1]==heal){
                    st.pop();
                    insert = false;
                    break;
                }
                else if(st.top()[1]>heal){
                    auto top = st.top();
                    st.pop();
                    st.push({top[0],top[1]-1, top[2]});
                    insert = false;
                    break;
                }
                else{
                    st.pop();
                    heal--;
                }
            }
            if(insert) st.push({terms[i][0] ,heal, 0});         

        }
        vector<vector<int>> ans;
        while(!st.empty()){
            auto top = st.top();
            ans.push_back({pos[top[0]], top[1]});
            st.pop();
        }
        
        sort(ans.begin(), ans.end());
        vector<int> res;
        for(auto ele: ans){
            res.push_back(ele[1]);
        }
        return res;
    }
};