class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<vector<int>> maxheap;
        queue<vector<int>> q;
        vector<int> count(26,0);
        for(char word: s){
            count[word-'a']++;
        }
        for(int i=0; i<26; i++){
            if(count[i]>0){
                maxheap.push({count[i], i});
            }
        }
        string ans;
        while(!maxheap.empty()){
            auto top = maxheap.top();
            ans.push_back(top[1]+'a');
            maxheap.pop();
            if(!q.empty()){
                auto ele = q.front();
                maxheap.push(ele);
                q.pop();
            }
            if(top[0]>1){
                q.push({top[0]-1, top[1]});
            }
        }
        if(!q.empty()){
            return "";
        }
        return ans;
    }
};