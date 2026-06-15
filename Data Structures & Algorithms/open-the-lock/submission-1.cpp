class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ends;
        for(string s: deadends){
            ends.insert(s);
        }
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({"0000",0});
        visited.insert("0000");
        int count = 0;

        string copy_add;
        string copy_subs;
        while(!q.empty()){
            string one = q.front().first;
            int count = q.front().second;
            q.pop();
            if(ends.count(one)) continue;
            if(one==target) return count;
            for(int i=0; i<4; i++){
                copy_add = one;
                copy_subs = one;
                if(copy_subs[i]=='0') copy_subs[i] = '9';
                else copy_subs[i]-=1;
                if(!visited.count(copy_subs)){
                     q.push({copy_subs, count+1});
                     visited.insert(copy_subs);
                }
                if(copy_add[i]=='9') copy_add[i] = '0';
                else copy_add[i]+=1;
                if(!visited.count(copy_add)){
                     q.push({copy_add, count+1});
                     visited.insert(copy_add);
                }
            }            
        }

        return -1;
    }
};