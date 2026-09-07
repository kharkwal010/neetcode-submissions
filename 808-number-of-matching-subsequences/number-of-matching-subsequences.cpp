class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<pair<string, int>>> buckets(26);
        for(string w: words){
            buckets[w[0]-'a'].push({w, 0});
        }
        int ans = 0;
        for(char c: s){
            int r = c-'a';
            queue<pair<string, int>> temp;
            while(!buckets[r].empty()){
                auto[st, index] = buckets[r].front();
                buckets[r].pop();
                if(index+1==st.size()) ans++;
                else{
                    int nr = st[index+1]-'a';
                    if(r==nr) temp.push({st, index+1});
                    else buckets[nr].push({st, index+1});
                }
            }
            buckets[r] = temp;
        }
        return ans;
    }
};