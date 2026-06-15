class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber>0){
            int c = columnNumber%26;
            columnNumber/=26;
            if(c==0){
                c=26;
                columnNumber--;
            }
            ans.push_back('A'+c-1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};