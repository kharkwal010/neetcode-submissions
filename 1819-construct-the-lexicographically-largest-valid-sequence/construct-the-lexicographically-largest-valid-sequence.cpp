class Solution {
public:
    vector<int> res;
    void backtrack(int n, vector<int>& ans, vector<bool>& used, int i, bool& end){
        if(end) return;
        if(n==0){
            res = ans;
            end = true;
            return;
        }
        while(i<ans.size() && ans[i]!=0) i++;
        for(int j=used.size()-1; j>0; j--){
            if(!used[j]){
                if(j!=1 && (i+j>=ans.size() || ans[i+j]!=0)) continue;
                used[j] = true;
                ans[i] = j;
                if(j!=1) ans[i+j]=j;
                backtrack(n-1, ans, used, i+1, end);
                used[j] = false;
                ans[i]=0;
                if(j!=1) ans[i+j]=0;
            }
        }
        return;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1, 0);
        vector<bool> used(n+1, false);
        bool end = false;
        backtrack(n, ans, used, 0, end);
        return res;
        
    }
};