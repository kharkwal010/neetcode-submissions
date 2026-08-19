class Solution {
public:
    string space(int n){
        if(n<0) return "";
        string s(n, ' ');
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        ans.push_back({});
        int i = 0;
        while(i<words.size()){
           int j = i;
        //    int used = 0;
           int len = 0;
           while(i<words.size() && len + words[i].size() + (i - j) <= maxWidth){
                // used += words[i].size() + 1;
                len += words[i].size();
                i++;
           }
           int n = i - j - 1;
           int total_space = maxWidth - len;
            if(i==words.size()){
                for(int k=j; k<i; k++){
                    ans.back() += (words[k]);
                    if(k==i-1) continue;
                    ans.back() += " ";
                }
                ans.back() += space(total_space - n);
                return ans;
            }

           
            //last line;

            if(n==0){
                ans.back() += (words[j]);
                ans.back() += (space(total_space));
            }
           else{
                int indi = total_space / n;
                int extra = total_space % n;
                for(int k=j; k<i; k++){
                    ans.back() += (words[k]);
                    if(k==i-1) break;
                    if(extra>0){
                        ans.back() += (space(indi+1));
                        extra--;
                    }
                    else ans.back() += (space(indi));
                }
           }
           ans.push_back({});

           
        }
        return ans;
    }
};