class Solution {
public:
    void all_comb(vector<string> letters, vector<string>& ans, string &comb, int layer){
        if (layer == letters.size()){
            ans.push_back(comb);
            return;
        }
        for (int i=0; i<letters[layer].size(); i++){
            comb.push_back(letters[layer][i]);
            all_comb(letters, ans, comb, layer+1);
            comb.pop_back();
            
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
       if (digits.empty()){
        return ans;
       }
       vector<string> letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       vector<string> usecase;
        for (int i=0; i<digits.size(); i++){
            int temp= digits[i] - '0';
            usecase.push_back(letters[temp]);
        }
        string comb;
        all_comb(usecase, ans, comb, 0);
        return ans;

    }
};
