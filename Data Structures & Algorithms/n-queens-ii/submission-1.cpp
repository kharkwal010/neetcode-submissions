class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> pdia;
    unordered_set<int> ndia;
    int queen(int n, int r){
        if(r==n) return 1;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(col.count(i)) continue;
            if(pdia.count(r+i)) continue;
            if(ndia.count(r-i)) continue;

            col.insert(i);
            pdia.insert(r+i);
            ndia.insert(r-i);
            ans = ans + queen(n, r+1);
            col.erase(i);
            pdia.erase(r+i);
            ndia.erase(r-i);
        }
        return ans;
    }
    int totalNQueens(int n) {
        return queen(n, 0);
    }
};