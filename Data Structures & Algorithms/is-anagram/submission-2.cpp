class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> a;
        unordered_map<char, int> b;
        for (char letter: s){
            a[letter]++;
        }
        for (char letter: t){
            b[letter]++;
        }
        if (a==b){
            return true;
        }
        else{
            return false;
        }
        

    }
};
