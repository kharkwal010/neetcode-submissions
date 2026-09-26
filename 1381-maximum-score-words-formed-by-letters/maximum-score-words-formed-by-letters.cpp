class Solution {
public:
    int solve(vector<string>& words, int i, vector<int>& freq, vector<int>& score){
        if(i==words.size()) return 0;
        int ans = 0;
        ans = max(ans, solve(words, i+1, freq, score));
        bool take = true;
        int val = 0;

        for(char c: words[i]){
            if(freq[c-'a']<=0){
                take = false;
            }
            freq[c-'a']--;
            val += score[c-'a'];
        }
        if(take) ans = max(ans, val + solve(words, i+1, freq, score));
        for(char c: words[i]){
            freq[c-'a']++;
        }
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        for(char c: letters) freq[c-'a']++;
        return solve(words, 0, freq, score);
                
    }
};