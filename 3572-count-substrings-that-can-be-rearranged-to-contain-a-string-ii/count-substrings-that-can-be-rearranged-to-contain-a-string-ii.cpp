class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        if(n<word2.size()) return 0;
        vector<int> freq(26,0);
        for(char c: word2){
            freq[c-'a']++;
        }
        int req = 0;
        for(int i=0; i<26; i++) if(freq[i]>0) req++;
        int l = 0;
        int r = 0;
        vector<int> res(26, 0);
        long long count = 0;
        while(r<word1.size()){
            int j = word1[r]-'a';
            res[j]++;
            if(res[j]==freq[j]) req--;
            while(req==0){
                count += (n - r);
                int k = word1[l]-'a';
                if(res[k]==freq[k]) req++;
                res[k]--;
                l++;
            }
            r++;
        }
        return count;
    }
};