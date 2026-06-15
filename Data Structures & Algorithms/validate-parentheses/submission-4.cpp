class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        
        for (char br : s){
            
            if( br =='}'){
                if (brackets.empty()==true){
                    return false;
                }
                char a = brackets.top();
                brackets.pop();
                if (a!='{'){
                    return false;
                }
            }
            if( br ==')'){
                if (brackets.empty()==true){
                    return false;
                }
                char a = brackets.top();
                 brackets.pop();
                if (a!='('){
                    return false;
                }
            }
            if( br ==']'){
                if (brackets.empty()==true){
                    return false;
                }
                char a = brackets.top();
                 brackets.pop();
                if (a!='['){
                    return false;
                }
            }
            if (br == '(' || br == '[' || br == '{')
            brackets.push(br);
                                      
        

        }
        if (brackets.empty()==true){
       return true;
        }
        return false;
       
    }
};
