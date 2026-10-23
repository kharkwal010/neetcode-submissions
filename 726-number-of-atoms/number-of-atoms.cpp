class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string, int>> st;
        int i = 0;
        while(i<formula.size()){
            if(formula[i]=='('){
                st.push({"(", 0});
                i++;
            }

            else if(formula[i]==')'){
                i++;
                int num = 0;
                while(formula[i]-'0'>=0 && formula[i]-'0'<=9){
                    num = num*10 + formula[i]-'0';
                    i++;
                }
                if(num==0) num = 1;
                stack<pair<string, int>> temp;
                while(st.top().first!="("){
                    auto curr = st.top();
                    st.pop();
                    temp.push({curr.first, curr.second*num});
                }
                st.pop();
                while(!temp.empty()){
                    st.push(temp.top());
                    temp.pop();
                }
            }

            else{
                string temp;
                temp.push_back(formula[i]);
                i++;
                while(formula[i]-'a'>=0 && formula[i]-'a'<=25){
                    temp.push_back(formula[i]);
                    i++;
                }
                int num = 0;
                while(formula[i]-'0'>=0 && formula[i]-'0'<=9){
                    num = num*10 + formula[i]-'0';
                    i++;
                }
                if(num==0) num = 1;
                st.push({temp, num});
            }
        }

        unordered_map<string, int> mp;
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            mp[top.first] += top.second;
        }
        vector<string> val;
        for(auto e: mp){
            val.push_back(e.first);
        }
        sort(val.begin(), val.end());
        string ans = "";
        for(int i=0; i<val.size(); i++){
            string num = to_string(mp[val[i]]);
            ans += val[i];
            if(num!="1") ans += num;
        }
        return ans;
    }
};