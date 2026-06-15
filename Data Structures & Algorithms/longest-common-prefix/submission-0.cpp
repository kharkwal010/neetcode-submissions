class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i=0; i<strs[0].size(); i++){
            int tar = strs[0][i];
            bool present = true;
            for(int j=1; j<strs.size(); j++){
                if(i>=strs[j].size() || strs[j][i]!=tar){
                    present = false;
                    break;
                }                
            }
            if(present) ans.push_back(tar);
            else break;
        }
        return ans;
    }
};