class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()) swap(a, b);
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        string s = "";
        while(j>=0){
            int term = (a[i]-'0') + (b[j]-'0') + carry;
            carry = term/2;
            term = term%2;
            s.push_back(term+'0');
            j--;
            i--;
        }

        while(i>=0){
            int term = (a[i]-'0') + carry;
            carry = term/2;
            term = term%2;
            s.push_back(term+'0');
            i--;            
        }

        if(carry==1) s.push_back('1');
        reverse(s.begin(), s.end());
        return s;
    }
};