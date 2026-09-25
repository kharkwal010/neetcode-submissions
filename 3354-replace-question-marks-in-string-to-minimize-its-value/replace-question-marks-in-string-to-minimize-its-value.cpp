class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq(26,0);
        for(char c: s){
           if(c!='?') freq[c-'a']++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> minheap;
        for(int i=0; i<26; i++){
            minheap.push({freq[i], 'a'+i});
        }
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='?'){
                auto curr = minheap.top();
                minheap.pop();
                ans.push_back(curr.second);
                minheap.push({curr.first+1, curr.second});
            }
        }
        sort(ans.begin(), ans.end());
        int j=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='?'){
                s[i] = ans[j];
                j++;
            }
        }
        return s;

    }
};