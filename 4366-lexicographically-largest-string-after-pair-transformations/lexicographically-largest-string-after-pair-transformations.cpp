class Solution {
public:
    // unordered_map<int, string> memo;
    string convert(int n){
        string ans;
        int c = 0;
        while(n>0){
            if(n%2==1){
                if(c<26) ans.push_back(c+'a');
                else ans += "zz";
            }
            n = n/2;
            c++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(int n: nums) ans.push_back(convert(n));
        return ans;
    }
};