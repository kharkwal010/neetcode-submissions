class Solution {
public:
    vector<string> terms(string sentence){
        stringstream ss(sentence);
        vector<string> values;
        string t;
        while(getline(ss, t, ' ')){
            values.push_back(t);
        }
        return values;
    }
    bool similar(vector<string>& one, vector<string>& two){
        int l = 0;
        int r = one.size()-1;
        int i = 0;
        int j = two.size()-1;
        while(l<=r){
            if(one[l]!=two[i]) break;
            l++;
            i++;
        }

        while(l<=r){
            if(one[r]!=two[j]) break;
            r--;
            j--;
        }
        // cout<<l<<" "<<r<<endl;
        return (l>r);
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> terms1 = terms(sentence1);
        vector<string> terms2 = terms(sentence2);
        bool res = false;
        if(terms1.size()>terms2.size()) res = similar(terms2, terms1);
        else res = similar(terms1, terms2);
        return res;
    }
};