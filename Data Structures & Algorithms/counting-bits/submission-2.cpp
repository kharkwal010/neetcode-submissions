class Solution {
public:    
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        int main = 1;
        for(int i=1; i<ans.size(); i++){
            if(i==main*2) main = i;
            ans[i] = 1 + ans[i-main];
        }
        return ans;
    }
};
