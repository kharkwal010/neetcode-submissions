class Solution {
public:
    string shortestPalindrome(string s) {
        vector<int> lps(s.size(), 0);
        int i = 1;
        int l = 0;
        while(i<s.size()){
            if(s[l]==s[i]){
                l++;
                lps[i] = l;
                i++;
            }
            else{
                if(l==0){
                    i++;
                    continue;
                }
                else l = lps[l-1];
            }
        }
        
        i=0;
        l=0;
        string t = s;
        reverse(s.begin(), s.end());
        swap(s, t);
        while(i<t.size()){
            if(t[i]==s[l]){
                l++;
                i++;
            }
            else{
                if(l==0){
                    i++;
                    continue;
                }
                else l = lps[l-1];
            }
        }
        string extra = s.substr(l);
        reverse(extra.begin(), extra.end());
        string ans = extra + s;
        return ans;

    }
};