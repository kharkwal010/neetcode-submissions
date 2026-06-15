class Solution {
public:

    string convertToTitle(int columnNumber) {
        int num = columnNumber;
        string ans = "";
        int term;
        while(num>0){            
            term = (num-1)%26;
            
            num = (num-1) / 26;
            ans = char(term + 'A' )+ ans;
        }
        return ans;
    }
};