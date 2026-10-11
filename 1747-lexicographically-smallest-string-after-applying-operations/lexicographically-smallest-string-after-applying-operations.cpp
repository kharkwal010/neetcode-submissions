class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        string ans = s;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            if(curr<ans) ans = curr;
            string temp = curr;
            for(int i=1; i<temp.size(); i+=2){
                char c = '0' + ((temp[i]-'0'+a)%10);
                temp[i] = c;
            }
            if(!visited.count(temp)){
                visited.insert(temp);
                q.push(temp);
            }
            int j = s.size()-b;
            string one = curr.substr(0, j);
            string two = curr.substr(j);
            string news = two + one;
            if(!visited.count(news)){
                visited.insert(news);
                q.push(news);
            }
        }
        return ans;
    }
};