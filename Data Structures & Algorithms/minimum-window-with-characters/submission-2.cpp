class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()==0 || t.size()>s.size()){
            return "";
        }
        string ans;
        unordered_map<char, int> tcount;
        unordered_map<char, int> scount;

        for(char ch: t){
            tcount[ch]++;
        }

        int required = tcount.size();
        int have = 0;
        int start = 0;
        for(int end = 0; end<s.size(); end++){
            if (tcount.find(s[end])!=tcount.end()){
                scount[s[end]]++;
                    if(scount[s[end]]==tcount[s[end]]){
                        have++;
                    }                
                
                while(have==required && start<=end){
                    if(tcount.find(s[start])!=tcount.end()){
                        if(ans.size()==0 || ans.size()>end-start+1){
                            ans = s.substr(start, end-start+1);
                        }
                        scount[s[start]]--;
                        if(scount[s[start]]<tcount[s[start]]){
                            have--;
                        }
                    }
                    start++;
                }
            }
        }
        return ans;
        
    }
};

