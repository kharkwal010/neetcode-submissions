class Solution {
public:
    bool check(vector<vector<int>>& terms){
        sort(terms.begin(), terms.end());
        int start = terms[0][0];
        int end = terms[0][1];
        int count = 0;
        for(int i=1; i<terms.size(); i++){
            while(i<terms.size() && end>terms[i][0]){
                end = max(end, terms[i][1]);
                i++;
            }
            if(i==terms.size()) break;
            count++;
            if(i<terms.size()){
                start = terms[i][0];
                end = terms[i][1];
            }
        }
        return count>=2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> row;
        for(auto ele: rectangles){
            row.push_back({ele[0], ele[2]});
        }
        if(check(row)) return true;
        vector<vector<int>> col;
        for(auto ele: rectangles){
            col.push_back({ele[1], ele[3]});
        }
        if(check(col)) return true;
        return false;
        
    }
};