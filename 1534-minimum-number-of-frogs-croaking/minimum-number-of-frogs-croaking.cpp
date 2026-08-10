class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<char> terms = {'c', 'r', 'o', 'a', 'k'};
        unordered_map<char, char> prev;
        prev['r'] = 'c';
        prev['o'] = 'r';
        prev['a'] = 'o';
        prev['k'] = 'a';
        unordered_map<char, int> freq;
        int ans = 0;
        for(char ch: croakOfFrogs){
            if(ch=='c'){
                freq[ch]++;
                ans = max(ans, freq[ch]);
            }
            else{
                if(freq[prev[ch]]<=freq[ch]) return -1;
                freq[ch]++;
            }
            if(ch=='k'){
                for(char c: terms) freq[c]--;
            }
        }
        if(freq['c']!=freq['k']) return -1;
        return ans;
    }
};