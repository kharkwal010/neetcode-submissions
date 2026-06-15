class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        priority_queue<pair<int, char>> maxheap;
        if(a>0) maxheap.push({a, 'a'});
        if(b>0) maxheap.push({b, 'b'});
        if(c>0) maxheap.push({c, 'c'});
        queue<pair<int, char>> q;
        while(!maxheap.empty()){
            int count = maxheap.top().first;
            char ch = maxheap.top().second;
            maxheap.pop();
            ans.push_back(ch);
            count--;
            if(!q.empty()){
                maxheap.push(q.front());
                q.pop();
            }
            if(count>0){
                if(ans.size()>=2 && ans[ans.size()-1]==ans[ans.size()-2]){
                    q.push({count,ch});
                }
                else maxheap.push({count, ch});                
           }
        }
        return ans;
    }
};