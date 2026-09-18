class Solution {
public:
    vector<vector<string>> terms;
    void comb(vector<string>& words, vector<string>& curr, int i){
        if(curr.size()==4){
            terms.push_back(curr);
            return;
        }
        if(i==words.size()) return;
        curr.push_back(words[i]);
        comb(words, curr, i+1);
        curr.pop_back();
        comb(words, curr, i+1);
        return;
    }
    void perm(vector<string>& words, int i, vector<vector<string>>& ans){
        if(i==4){
            if(words[0][0]==words[1][0]){
                if(words[0][3]==words[2][0]){
                    if(words[3][0]==words[1][3]){
                        if(words[3][3]==words[2][3]){
                            ans.push_back(words);
                        }
                    }
                }
            }
            return;
        }
        for(int j=i; j<4; j++){
            swap(words[j], words[i]);
            perm(words, i+1, ans);
            swap(words[j], words[i]);
        }
        return;
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<string> curr;
        comb(words, curr, 0);
        vector<vector<string>> ans;
        // cout<<terms.size()<<endl;
        for(auto ele: terms){
            perm(ele, 0, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};