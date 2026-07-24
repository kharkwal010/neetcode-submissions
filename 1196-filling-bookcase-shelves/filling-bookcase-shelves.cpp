class Solution {
public:
    vector<int> memo;
    int height(vector<vector<int>>& books, int& width, int i){
        if(i==books.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        int wide = 0;
        int ans = INT_MAX;
        int high = 0;
        for(int j=i; j<books.size(); j++){
            wide += books[j][0];
            high = max(high, books[j][1]);
            if(wide>width) break;
            ans = min(ans, high + height(books, width, j+1));            
        }
        return memo[i] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memo.resize(books.size(), -1);
        return height(books, shelfWidth, 0);

    }
};