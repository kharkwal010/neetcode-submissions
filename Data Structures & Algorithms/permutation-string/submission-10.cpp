class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int> count(26,0);
       if(s1.size()>s2.size()){
            return false;
       }
       for(int i=0; i<s1.size(); i++){
            count[s1[i]-'a']++;
       }
       int len = s1.size();
       vector<int> second(26,0);
       for(int i=0; i<s1.size(); i++){
            second[s2[i]-'a']++;
       }
       int start = 0;
       for(int i=0; i<s2.size()-len+1; i++){
        if(count == second){
            return true;
        }
        second[s2[i]-'a']--;
        start++;
        second[s2[i+len]-'a']++;
        
       }
       return false;
    }

};
