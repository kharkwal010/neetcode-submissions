class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        int curr = 1;
        for(int i=1; i<ans.size(); i++){
            ans[i] = ans[i-curr]+1;
            if((i+1)%curr==0) curr*=2;
        }
        return ans;
    }
};
