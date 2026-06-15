class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i]>0){
                s.push(asteroids[i]);
            }
            else{
                bool enter = true;
                while(!s.empty() && s.top()>0 && abs(asteroids[i])>=s.top()){
                    if(abs(asteroids[i])==s.top()){
                        s.pop();
                        enter = false;
                        break;
                    }
                    s.pop();
                }
                if((s.empty()  || s.top()<0) && enter){
                    s.push(asteroids[i]);
                }
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};