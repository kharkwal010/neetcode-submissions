class Solution {
public:
    string simplifyPath(string path) {
        int s = 0;
        stack<string> st;
        for(int i=0; i<path.size(); i++){
            if(path[i]=='/'){
                s=i+1;
                continue;
            }
            while(i<path.size() && path[i]!='/'){
                i++;
            }
            int len = i - s;
            i--;
            string sub = path.substr(s, len);
            if(sub==".") continue;
            else if(sub==".."){
                if(!st.empty()) st.pop();
            }
            else st.push(sub);
        }
        string ans;
        while(!st.empty()){
            string ele = st.top();
            st.pop();
            ans =  "/" + ele + ans;
        }
        if(ans.size()==0) return "/";
        return ans;
    }
};