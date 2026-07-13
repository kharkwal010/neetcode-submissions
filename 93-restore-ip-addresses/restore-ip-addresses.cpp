class Solution {
public:
    void addresses(string s, int t, int i, string comb, vector<string>& ans){
        if(i==s.size()){
            if(t<4) return;
            comb.pop_back();
            ans.push_back(comb);
            return;
        }
        if(t==4) return;
        if(s[i]=='0'){
            comb+="0.";
            addresses(s, t+1, i+1, comb, ans);
        }
        else{
            string curr;
            string temp = comb;
            for(int j=i; j<i+4; j++){
                if(j==s.size()) break;
                curr += s[j];
                if(stoi(curr)>255) break;
                comb += curr + ".";
                // cout<<comb<<endl;
                addresses(s, t+1, j+1, comb, ans);
                comb = temp;
            }
        }
        return;

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        addresses(s, 0, 0, "", ans);
        return ans;
    }
};