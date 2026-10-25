class Solution {
public:
    int memo[100][100][100];
    int score(vector<int>& boxes, int l, int r, int extra){
        if(l>r) return 0;
        if(memo[l][r][extra]!=-1) return memo[l][r][extra];
        int i = l;
        int curr = boxes[l];
        int count = 0;
        while(i<=r && boxes[i]==curr){
            count++;
            i++;
        }
        count += extra;
        int ans = 0;
        ans = max(ans, count*count + score(boxes, i, r, 0));
        for(int k=i; k<=r; k++){
            if(boxes[k]==curr){
                ans = max(ans, score(boxes, k, r, count) + score(boxes, i, k-1, 0));
                // ans = max(ans, count*count + score(boxes, j, k-1) + score(boxes, k+1, r));
            }
        }
        return memo[l][r][extra] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(memo, -1, sizeof(memo));
        return score(boxes, 0, boxes.size()-1, 0);
    }
};