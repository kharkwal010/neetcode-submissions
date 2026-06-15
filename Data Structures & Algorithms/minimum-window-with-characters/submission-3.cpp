class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        if(t.size()>s.size()) return ans;
        unordered_map<char, int> tchar;
        unordered_map<char, int> schar;
        for(char ele: t){
            tchar[ele]++;
        }
        int tcount = tchar.size();
        int scount = 0;

        int st = 0;
        for(int e=0; e<s.size(); e++){
            if(tchar.find(s[e])!=tchar.end()){
                schar[s[e]]++;
                if(schar[s[e]]==tchar[s[e]]) scount++;
            }
            if(scount==tcount){
                while(st<=e){
                    if(schar.find(s[st])!=schar.end()){
                        schar[s[st]]--;
                        if(schar[s[st]]<tchar[s[st]]){
                            scount--;
                        }
                    }
                    st++;
                    if(scount!=tcount){
                        string temp = s.substr(st-1, e-st+2);
                        if(ans.size()==0 || ans.size()>temp.size()){
                            ans = temp;
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
