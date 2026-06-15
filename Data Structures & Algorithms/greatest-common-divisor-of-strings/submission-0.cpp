class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int one = str1.size();
        int two = str2.size();
        int n = gcd(one, two);
        string ans = str1.substr(0,n);
        int rep1 = one / n;
        int rep2 = two / n;
        string s1 = "";
        string s2 = "";
        for(int i=0; i<rep1; i++){
            s1= ans + s1;
        }
        for(int i=0; i<rep2; i++){
            s2 = ans + s2;
        }
        if(s1==str1 && s2==str2){
            return ans;
        }
        return "";       

    }
};