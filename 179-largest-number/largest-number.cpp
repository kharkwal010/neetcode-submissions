class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> terms;
        for(int n: nums) terms.push_back(to_string(n));
        sort(terms.begin(), terms.end(), [](auto& a, auto& b){
            return a+b > b+a;
        });
        string ans = "";
        for(string t: terms) ans+=t;
        return (ans[0]=='0') ? "0" : ans;
    }
};