class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unique;
        int one=0;
        int two =1;
        int length = 1;
        if(s.size()==0){
            return 0;
        }
        unique.insert(s[one]);
        while(two<s.size()){
            if (one == two){
            unique.insert(s[two]);  // ✅ Insert the character at `two` before moving ahead
            two++;
            continue;               // ✅ Skip rest of loop for this step
}

            
            if (!(unique.empty()) && unique.find(s[two])==unique.end()){
                unique.insert(s[two]);
                two++;
            }
            else{
                unique.erase(s[one]);
                one++;
                
            }
            length = max(length, int(unique.size()));
        }
        return length;
    }
};
