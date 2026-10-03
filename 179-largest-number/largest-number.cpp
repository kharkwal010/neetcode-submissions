class Solution {
public:
    // i think we need to cyclic sort it....
    string largestNumber(vector<int>& nums) {
       vector<string> terms;
       for(int n: nums) terms.push_back(to_string(n));
       sort(terms.begin(), terms.end(), [] (auto& a, auto& b){
        return a+b>b+a;
       });
       string ans = "";
       for(string t: terms) ans += t;
       if(ans[0]=='0') return "0";
       return ans;
    }
};