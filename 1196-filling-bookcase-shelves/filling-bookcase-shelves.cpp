class Solution {
public:
    unordered_map<int, int> memo;
    int height(vector<vector<int>>& books, int width, int i){
        if(i==books.size()) return 0;
        if(memo.count(i)) return memo[i];
        int high = 0;
        int wide = 0;
        int ans = INT_MAX;
        for(int j=i; j<books.size(); j++){
            if(width - wide< books[j][0]) break;
            wide += books[j][0];
            high= max(books[j][1], high);
            ans = min(ans, high + height(books, width, j+1));
        }
        memo[i] = ans;
        return memo[i];
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        return height(books, shelfWidth, 0);
    }
};