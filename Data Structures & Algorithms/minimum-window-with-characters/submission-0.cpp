class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()==0){
            return "";
        }
       unordered_map<char, int> countt;
       unordered_map<char, int> counts;
       for(int i=0; i<t.size(); i++){
        countt[t[i]]++;
       }
      
       int have = 0;
       int start = 0;
       string ans;

       for(int end = 0; end<s.size(); end++){
        counts[s[end]]++;
        if(countt.find(s[end])!=countt.end() && counts[s[end]]==countt[s[end]]){
            have++;
            while(have==countt.size()){
                string temp = s.substr(start, end-start+1);
                if(temp.size()<ans.size() || ans.size()==0){
                    ans = temp;
                }
                counts[s[start]]--;
                if(countt.find(s[start]) != countt.end() && counts[s[start]]<countt[s[start]]){
                    have--;
                    
                }
                start++;
            }  
            
        }
       }
       return ans;
        
    }
};

