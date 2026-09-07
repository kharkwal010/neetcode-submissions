class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> terms(numRows, "");
        bool down = true;
        int j=0;
        for(int i=0; i<s.size(); i++){
            terms[j].push_back(s[i]);
            if(down){
                j++;
                if(j==terms.size()){
                    j=terms.size()-2;
                    down = false;
                }
            }
            else{
                j--;
                if(j<0){
                    j=1;
                    down = true;
                }
            }
        }
        string ans = "";
        for(string ele: terms){
            ans+=ele;
        }
        return ans;
    }
};