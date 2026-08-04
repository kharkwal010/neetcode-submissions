class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> temp;
        vector<int> ans;
        int n = words.size();
        for(string& w: words){
            temp[w]++;
        }
        int sz = words[0].size();
        for(int i=0; i<sz; i++){
            vector<string> subs;
            for(int j=i; j<s.size(); j+=sz){
                if(j+sz<=s.size()){
                    subs.push_back(s.substr(j, sz));
                }
            }
            int l = 0;
            int r = 0;
            int count=0;
            unordered_map<string, int> terms = temp;
            while(r<subs.size()){
                if(terms[subs[r]]>0){
                    terms[subs[r]]--;
                    count++;
                    if(count==n){
                        ans.push_back(i+l*sz);
                        terms[subs[l]]++;
                        count--;
                        l++;
                    }
                    r++;
                }
                else{
                    if(l==r){
                        l++;
                        r++;
                    }
                    else{
                        terms[subs[l]]++;
                        count--;
                        l++;
                    }
                }
            }
            
        }
        return ans;
    }
};