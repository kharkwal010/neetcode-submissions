class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector <int> first(26,0);
        vector <int> second(26,0);
        if (s1.size() > s2.size()) return false;

        for (int i=0; i<s1.size(); i++){
            first[s1[i]-'a']++;
        }
        for (int i=0; i<s1.size(); i++){
            second[s2[i]-'a']++;
        }
        int match=0;
        for (int i=0; i<26; i++){
            if (first[i]==second[i]){
                match++;
            }
        }
        if (match==26){
            return true;
        }
        int left =0;
        int right = s1.size();
        while (right <s2.size()){
            int in = s2[right++] - 'a';
            int out = s2[left++] - 'a';

            // handle outgoing character
            if (second[out] == first[out]) match--;  // was equal
            second[out]--;
            if (second[out] == first[out]) match++;  // is equal now

            // handle incoming character
            if (second[in] == first[in]) match--;    // was equal
            second[in]++;
            if (second[in] == first[in]) match++;    // is equal now

           
            if (match==26){
                return true;
            }

        }
        return false;


    }

};
