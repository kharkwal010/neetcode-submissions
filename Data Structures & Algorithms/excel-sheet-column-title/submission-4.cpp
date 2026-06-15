class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber>0){
            int term = (columnNumber-1)%26;
            ans.push_back('A'+term);
            columnNumber = (columnNumber-1)/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};