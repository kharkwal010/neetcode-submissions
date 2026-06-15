class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> remove;
        int open = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==')'){
                open--;
                if(open<0){
                    remove.insert(i);
                    open = 0;
                }
            }
            else if(s[i]=='('){
                open++;
            }
        }

        int i=s.size()-1;
        while(open>0){
            if(s[i]=='('){
                remove.insert(i);
                open--;
            }
            i--;
        }
        string ans;
        for(int i=0; i<s.size(); i++){
            if(remove.count(i)) continue;
            ans.push_back(s[i]);
        }
        return ans;
        
    }
};
