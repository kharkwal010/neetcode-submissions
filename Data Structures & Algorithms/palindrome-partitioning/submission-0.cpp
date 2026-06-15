class Solution {
public:
    set<vector<string>> check;

    bool palin(string s){
        
        int left =0;
        int right = s.size()- 1;
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }   
                left++;
                right--;
            
        }
        return true;

    }
    void palindrome(string s, vector<vector<string>>& ans, vector<string>& element){
        if (s.size()==0){
            ans.push_back(element);
            return;
        }
        for (int i= 0; i<s.size(); i++){
            string sub=s.substr(0, i+1);
            if(palin(sub)){
                element.push_back(sub);
                palindrome(s.substr(i+1), ans, element);
                element.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> element;
        palindrome(s, ans, element);
        return ans;
        
    }
};
