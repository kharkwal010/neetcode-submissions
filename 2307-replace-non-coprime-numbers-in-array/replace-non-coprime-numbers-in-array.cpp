class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for(int n: nums){
            int curr = n;
            while(!st.empty()){
                int top = st.top();
                if(gcd(curr, top)==1) break;
                st.pop();
                curr = lcm(curr, top);
            }
            st.push(curr);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};