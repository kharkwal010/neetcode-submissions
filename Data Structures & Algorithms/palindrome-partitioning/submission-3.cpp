class Solution {
public:
bool palin(string s){
    int left = 0;
    int right = s.size()-1;
    while(left<right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
void palindromes(string s, vector<vector<string>>& result, vector<string> ans, int index){
    if(index==s.size()){
        result.push_back(ans);
        return;
    }
    for(int i=index; i<s.size(); i++){
        string sub = s.substr(index, i-index+1);
        if(palin(sub)){
            ans.push_back(sub);
            palindromes(s, result, ans, index+sub.size());
            ans.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
      vector<vector<string>> result;
      vector<string> ans;
      palindromes(s, result, ans, 0);
      return result;
            
    }    
};