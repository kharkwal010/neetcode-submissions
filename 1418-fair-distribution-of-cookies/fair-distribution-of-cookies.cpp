class Solution {
public:
    void backtrack(vector<int>& cookies, int i, vector<int>& dis, int& ans){
        if(i==cookies.size()){
            int maxi = 0;
            for(int j=0; j<dis.size(); j++) maxi = max(maxi, dis[j]);
            ans = min(ans, maxi);
            return;
        }
        unordered_set<int> terms;
        for(int j=0; j<dis.size(); j++){
            if(terms.count(dis[j])) continue;
            terms.insert(dis[j]);
            dis[j] += cookies[i];
            backtrack(cookies, i+1, dis, ans);
            dis[j] -= cookies[i];
        }
        return;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dis(k, 0);
        int ans = INT_MAX;
        backtrack(cookies, 0, dis, ans);
        return ans;

    }
};