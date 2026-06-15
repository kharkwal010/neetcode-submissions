class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.size();
        int l2 = str2.size();
        int ans = gcd(l1,l2);
        string s = str1.substr(0, ans);
        int one = l1/ans;
        string s1;
        for(int i=0; i<one; i++){
            s1 += s;
        }
        if(s1!=str1) return "";
        one = l2/ans;
        string s2;
        for(int i=0; i<one; i++){
            s2 += s;
        }
        if(s2!=str2) return "";

        return s;
    }
};