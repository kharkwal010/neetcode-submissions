class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(string ele: operations){
            if(ele=="+"){
                int one = s.top();
                s.pop();
                int two = s.top();
                s.pop();
                s.push(two);
                s.push(one);
                s.push(one+two);
            }
            else if(ele=="C"){
                s.pop();
            }
            else if(ele=="D"){
                int top = (s.top());
                top = 2* top;
                s.push(top);
            }
            else{
                s.push(stoi(ele));
            }
        }
        int sum = 0;
        while(!s.empty()){
            sum = sum + s.top();
            s.pop();
        }
        return sum;
    }
};