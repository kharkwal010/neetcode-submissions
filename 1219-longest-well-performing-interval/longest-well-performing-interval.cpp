class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> index;
        index[0] = -1;
        for(int i=0; i<hours.size(); i++){
            if(hours[i]>8) sum += 1;
            else sum -= 1;
            if(sum>0) ans = max(ans, i+1);
            else if(index.count(sum-1)) ans = max(ans, i - index[sum-1]);
            if(!index.count(sum)) index[sum] = i;
        }
        return ans;
    }
};