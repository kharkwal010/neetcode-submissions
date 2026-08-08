class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> present;
        unordered_map<char, int> letters;
        int r = 0;
        int count = 0;
        while(r<minSize){
            letters[s[r]]++;
            r++;
        }
        if(letters.size()<=maxLetters){
            string sub = s.substr(0, r);
            count = 1;
            present[sub]++;
        }
        int l = 0;
        while(r<s.size()){
            letters[s[r]]++;
            letters[s[l]]--;
            if(letters[s[l]]==0) letters.erase(s[l]);
            l++;
            r++;
            if(letters.size()<=maxLetters){
                string sub = s.substr(l, minSize);
                present[sub]++;
                count = max(count, present[sub]);
            }
        }
        return count;

    }
};