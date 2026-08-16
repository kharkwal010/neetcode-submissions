class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int len = 0;
        unordered_map<char, char> prev;
        prev['a'] = ' ';
        prev['e'] = 'a';
        prev['i'] = 'e';
        prev['o'] = 'i';
        prev['u'] = 'o';
        char pre = ' ';
        int l = 0;
        int ans = 0;
        for(int i=0; i<word.size(); i++){
            if(!(prev[word[i]]==pre || word[i]==pre)){
                if(word[i]=='a'){
                    pre = 'a';
                    l = i;
                }
                else{
                    pre = ' ';
                    l = i+1;  
                }
                            
                continue;
            }
            pre = word[i];
            if(word[i]=='u'){
                // cout<<i<<" "<<l<<endl;
                ans = max(ans, i - l + 1);
            }
        }
        return ans;
    }
};