class Solution {
public:
    string largestEven(string s) {
        string temp = s;
        for(int i=s.size()-1; i>=0; i--){
            if((s[i]-'0')%2==0) break;
            temp.pop_back();

        }
        return temp;
    }
};