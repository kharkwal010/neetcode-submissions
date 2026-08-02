class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> end;
        for(string& s: deadends){
            end.insert(s);
        }
        int count = 0;
        queue<string> q;
        q.push("0000");
        if(end.count("0000")) return -1;
        end.insert("0000");
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                string curr = q.front();
                q.pop();
                if(curr==target) return count;
                for(int i=0; i<4; i++){                    
                    string term = curr;
                    char ori = term[i];
                    if(ori=='9') term[i] = '0';
                    else term[i] = term[i] + 1;
                    if(!end.count(term)){
                        end.insert(term);
                        q.push(term);
                    }                    
                    if(ori=='0') term[i] = '9';
                    else term[i] = ori - 1;
                    if(!end.count(term)){
                        end.insert(term);
                        q.push(term);
                    } 
                }
            }
            count++;
        }
        return -1;       

    }
};