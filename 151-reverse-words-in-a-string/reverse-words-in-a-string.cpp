class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' ') continue;
            int j = i;
            while(j<s.size() && s[j]!=' '){
                j++;
            }
            words.push_back(s.substr(i, j-i));
            i=j;
        }
        string ans;
        for(int i=words.size()-1; i>=0; i--){
            ans += words[i];
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};