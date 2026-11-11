class Solution {
public:
    vector<int> memo;
    int solve(vector<vector<int>>& books, int& shelf, int i){
        if(i==books.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        int height = books[i][1];
        int w = books[i][0];
        int ans = INT_MAX;
        ans = min(ans, height + solve(books, shelf, i+1));
        for(int j = i+1; j<books.size(); j++){
            if(w + books[j][0] > shelf) break;
            w += books[j][0];
            height = max(height, books[j][1]);
            ans = min(ans, height + solve(books, shelf, j+1));
        }
        return memo[i] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        memo.resize(n, -1);
        return solve(books, shelfWidth, 0);
    }
};