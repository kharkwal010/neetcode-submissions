class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> value;
        for (string num: tokens){
            
            if (num!="+" && num!="-"&& num!="*"&& num!="/" ){
                int number = stoi(num);
                value.push(number);
                
            }
            else{
                int b = int(value.top());
                value.pop();
                int a= int(value.top());
                value.pop();
                if (num == "+"){
                    value.push(a+b);
                } 
                if (num == "-"){
                    value.push(a-b);
                }
                if (num == "*"){
                    value.push(a*b);
                } 
                if (num == "/"){
                    value.push(a/b);
                }           
            }

        }

        return value.top();
    }
};
