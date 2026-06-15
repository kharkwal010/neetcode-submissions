class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pos(n,1);
        while(m>1){
            for(int i=n-2; i>=0; i--){
                pos[i] = pos[i] + pos[i+1];
            }
            m--;
        }
        return pos[0];
    }
};
