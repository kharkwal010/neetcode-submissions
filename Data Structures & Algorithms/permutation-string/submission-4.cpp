class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // if(s2.size()<s1.size()){
        //     return false;
        // }
        sort(s1.begin(), s1.end());
        int len = s1.size();
        for(int i=0; i<=int(s2.size()-s1.size()); i++){
            string sub = s2.substr(i, len);
            sort(sub.begin(), sub.end());
            if(sub == s1){
                return true;
            }
        }
        return false;
    }

};
